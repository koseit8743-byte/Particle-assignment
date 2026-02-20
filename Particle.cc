#include "Particle.h"

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

}

float Particle::getRow() const{
return row;
}
float Particle::getCol()const{return col;}

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

void Physics(World& physics) {
	float  x_vel = 0;
	float  y_vel = -9.8; //this should default to gravity (otherwise user can eidt it)
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
void Particle::setColor(uint8_t Red, uint8_t Green, uint8_t Blue){
	red = Red;
	green = Green;
	blue = Blue;
}

void Particle::setVel( float xvel, float yvel){
	x_vel = xvel;
	y_vel = yvel;
}
