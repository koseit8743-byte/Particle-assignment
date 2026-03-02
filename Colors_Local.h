#ifndef COLORS_LOCAL_H
#define COLORS_LOCAL_H
#include <cstdint>
#include "Particle.h"

 struct Color { 
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

Color ParticleColor(ParticleType type);

#endif
