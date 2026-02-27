#include "Particle.h"
#include "World.h"
#include "Colors.h"
#include <cstdint>
#include <numeric>
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

void Particle::Physics(World& World_Map) {		
	col += x_vel; //this allows the x velocity to change
	row += y_vel; //this allows the y velocity to change		

	if (lifetime > 0) lifetime--; //decrements lifetime

	if (type == ParticleType::AIR) { 
		if (x_vel >= y_vel) 
			y_vel = 1.3f;
		if (y_vel >= x_vel) 
			x_vel = 1.2f;
		if (y_vel == 0)
			y_vel *= -1;
		if (x_vel == 0)
			x_vel *= -1;
	}
	if (type == ParticleType::DIRT) { 
		y_vel = -1;
		if (y_vel == 0 and x_vel == 0) 
		setStill(true);
	} 
	if (type == ParticleType::FIRE) { //If fire explodes maybe add particles in different directions to each one 
	//	isTouching();
	}

	if (type == ParticleType::EARTH) { 
		lifetime = -1;
		isStill();
		lifetime = -1;
	}
	if (type == ParticleType::WATER) {
		lifetime = 10;
		 if (World_Map.isEmpty(row, col + 1)) { //Should check to see if the spot to the right is open
			x_vel = 0;
			y_vel = -1;
		}
		 else if (World_Map.isEmpty(row, col - 1)) { 
			x_vel = 0;
			y_vel = -1;
		 }
	}

}

void Particle::getColor(uint8_t & r, uint8_t & g, uint8_t & b) const{
	r = red;
	g = green;
	b  = blue;
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
void Particle::isTouching(Particle& ParticleType, World& World_Map) { 

		for (const auto& temp : World_Map.Elements()) {
			if (ParticleType.getRow() == temp.getRow() and ParticleType.getCol() == temp.getCol() and ParticleType.getType() == ParticleType::FIRE and temp.getType() == ParticleType::WATER) {
			type = ParticleType::AIR;		
			if (ParticleType.getRow() == temp.getRow() and ParticleType.getCol() == temp.getCol() and ParticleType.getType() == ParticleType::LIGHTNING and temp.getType() == ParticleType::WATER)
				type = ParticleType::LIGHTNING;
			if (ParticleType.getRow() == temp.getRow() and ParticleType.getCol() == temp.getCol() and ParticleType.getType() == ParticleType::LIGHTNING and temp.getType() == ParticleType::EARTH)
				type = ParticleType::DIRT;
				
		}
	}
	/*Particle* touching at(int r, int c);
	//for (int i = 0; i < World_Map.size(); i++) 
	if (touching != nullptr) {
	if (touching->getType() == ParticleType::WATER)
	touching->setType(ParticleType::AIR);
	*/
	} 


void Particle::setVel( float xvel, float yvel){
	x_vel = xvel;
	y_vel = yvel;
}
