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

int Particle::getRow() const{
	return row;
}
int Particle::getCol()const{
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

	if (lifetime > 0) lifetime--;

	/*	if (type == ParticleType::AIR)

		if (type == ParticleType::DIRT) 

		if (type == ParticleType::FIRE) { 

		}

		if (type == ParticleType::FIRE) {

		}

		if (type == ParticleType::EARTH) 



	//Particle* set_velocity.at(x_vel,y_vel);
	if (it->getType() == ParticleType::AIR)		
	this->set_velocity(0,9.8);

*/
}

void Particle::getColor( uint8_t & r, uint8_t & g, uint8_t & b) const{
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
//bool Particle::isTouching() 
/*	//Particle* touching at(int r, int c);
	//for (int i = 0; i < World_Map.size(); i++) 
	if (touching != nullptr) {
	if (touching->getType() == ParticleType::WATER)
	touching->setType(ParticleType::AIR);

	} */


void Particle::setVel( float xvel, float yvel){
	x_vel = xvel;
	y_vel = yvel;
}
