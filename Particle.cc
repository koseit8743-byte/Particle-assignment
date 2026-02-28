#include "Particle.h"
#include "World.h"
#include "Colors.h"
#include <condition_variable>
#include <cstdint>
#include <numeric>
#include<cstdlib>

#include <sys/types.h>
Particle::Particle(float row1, float col1, ParticleType Type){
	row = row1;
	col = col1;
	type = Type;
	still = false;
	x_vel = 0.0f;
	y_vel = 0.0f;
	lifetime = -1;

	Color color = ParticleColor(type);

	red = color.red;
	green = color.green;
	blue = color.blue;
}

float Particle::getRow() const{
	return row;
}
float Particle::getCol()const{
	return col;
}

ParticleType Particle::getType() const {
	return type;
}

bool Particle::isStill() const{
	return still;
}

float Particle::getXvel() const {
	return x_vel;
}

float Particle::getYvel() const{
	return y_vel;
}


int Particle::getLifetime() const {
	return lifetime;
}
 void Particle::getColor(uint8_t & r, uint8_t & g, uint8_t & b) const{
     r = red;
     g = green;
     b = blue;
  }
void Particle::setRow(float r, float c) {
     row = r;
     col = c;
  }

 void Particle::setStill(bool isStill){
    still = isStill;
     if (x_vel == 0 && y_vel == 0)
      isStill = true;
  }
 void Particle::setLifetime(int frames){ lifetime = frames;}

 ParticleType Particle::setType(ParticleType newType) {
     type = newType;
     return type;
  }

 void Particle::setColor(uint8_t Red, uint8_t Green, uint8_t Blue){
     red = Red;
     green = Green;
     blue = Blue;
  }
 void Particle::setVel( float xvel, float yvel){
   x_vel = xvel;
     y_vel = yvel;
  }

void Particle::Physics(World& World_Map) {		
	col += x_vel; //this allows the x velocity to change
	row += y_vel; //this allows the y velocity to change		

	if (lifetime > 0) lifetime--; //decrements lifetime

	if (type == ParticleType::AIR) { 
		float airRow = row + y_vel;
		float airCol = col + x_vel;
		if (World_Map.at(airRow, airCol) == nullptr){
			row = airRow;
			col = airCol;
		}
		else { 
			x_vel *= -1;
			y_vel *= -1;
		}
	}
	if (type == ParticleType::DIRT) {
		setStill(true);
		if (World_Map.at(row + 1, col) == nullptr){
				row = row + 1;
				}
	else if ( World_Map.at(row + 1, col - 1) == nullptr){
			row = row + 1;
			col -= 1;
			}
	else if (World_Map.at(row + 1, col + 1) == nullptr){
			row += 1;
			col = col + 1;
			}
			
	}
	
	else if (type == ParticleType::DUST){
		setStill(false);
		if(World_Map.at(row + 1, col) == nullptr){
			row = row + 1;
		}
		
		if ( rand() % 2 == 0) { 
			if (World_Map.at(row, col - 1 ) == nullptr ){
				col -= 1;}
				else {
					if (World_Map.at( row, col + 1 ) == nullptr) { col = col+1;}
				}
			}
	}
	
	else if (type == ParticleType::FIRE) {
		if (rand () % 100 < 7) {
		//If fire explodes maybe add particles in different directions to each one
			float FireRow = row;
			float FireCol = col;
			Particle* Touch = World_Map.at(FireRow, FireCol);
			if (Touch == nullptr) { 
				row = (int)FireRow;
				col = (int)FireCol;
			}
			else { 
				isTouching(*Touch, World_Map);
			}
		}
	}

   else	if (type == ParticleType::EARTH) {
	   setStill(true);
	}
	else if ( type == ParticleType::LIGHTNING){
	if (lifetime <= 0 ) return;

	float LightRow = row + y_vel;
	float LightCol = col + x_vel;
	Particle* HIT = World_Map.at(LightRow, LightCol);
	if (HIT == nullptr) { 
	row = LightRow;
	col = LightCol;
	}
	else {
	isTouching(*HIT, World_Map);
	   lifetime = 0;
	   }
	}
	else if (type == ParticleType::WATER) {
		lifetime = -1;
		if(World_Map.at(row + 1, col) == nullptr){ 
			row += 1;
		}
		else if(World_Map.at(row + 1, col -1) == nullptr){
			row = row + 1; 
			col -= 1;
		}
		else if(World_Map.at(row + 1, col +1 ) == nullptr){
			row += 1;
			col = col + 1;
		}

		else if(World_Map.at(row , col + 1) == nullptr){
			col += 1;
		}
		else if(World_Map.at(row, col - 1) == nullptr){
			col -= 1;
		}
	}
}

/*void Particle::isTouching(Particle& ParticleType, World& World_Map) { 
=======
}

void Particle::isTouching(Particle& ParticleType, World& World_Map) { 
>>>>>>> ccba95baf876d9dc7c99c6a69c22ce67e12a714e
		for (const auto& temp : World_Map.Elements()) {
			if (ParticleType.getRow() == temp.getRow() and ParticleType.getCol() == temp.getCol() and ParticleType.getType() == ParticleType::FIRE and temp.getType() == ParticleType::WATER) {
				type = ParticleType::AIR;		
			if (ParticleType.getRow() == temp.getRow() and ParticleType.getCol() == temp.getCol() and ParticleType.getType() == ParticleType::LIGHTNING and temp.getType() == ParticleType::WATER)
				type = ParticleType::LIGHTNING;
			if (ParticleType.getRow() == temp.getRow() and ParticleType.getCol() == temp.getCol() and ParticleType.getType() == ParticleType::LIGHTNING and temp.getType() == ParticleType::EARTH)
				type = ParticleType::DIRT;
				
		}
	}
} */

void Particle::isTouching(Particle& Particle, World& World_Map) {
	if (this->type == ParticleType::WATER and Particle.getType() == ParticleType::FIRE) { 
		Particle.setType(ParticleType::AIR);
	}
	if (this->type == ParticleType::LIGHTNING and Particle.getType() == ParticleType::WATER) {
		Particle.setType(ParticleType::LIGHTNING);
	}
	if (this->type == ParticleType::LIGHTNING and Particle.getType() == ParticleType::EARTH) { 
		Particle.setType(ParticleType::DIRT);
	}
}



