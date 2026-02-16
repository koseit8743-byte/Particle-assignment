#include "Particle.h"

Particle::Particle(float row1, float col1, ParticleType Type){
	row = row1;
	col = col1;
	type = Type;
	still = false;
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

void Particle::setRow(float r, float c) {
	row = r;
	col = c;
}

void Particle::setStill(bool isStill){
	still = isStill;
}
