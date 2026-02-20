#include "Particle.h"

#include <cstdint>
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
float Particle::
void Particle::setRow(float r, float c) {
	row = r;
	col = c;
}

void Particle::setStill(bool isStill){
	still = isStill;
}


