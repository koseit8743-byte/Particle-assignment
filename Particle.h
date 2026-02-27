#ifndef PARTICLE_H
#define PARTICLE_H

#include <cstdint>
#include <ios>

enum class ParticleType {
	AIR, 
	LIGHTNING,
	DIRT,
	EARTH,
	WATER,
	DUST,
	FIRE,
};

class World;

class Particle {
	private:
		float row, col;  // location
		int x, y;
		float x_vel, y_vel; // velocity/ movement for x and y
		uint8_t red, green, blue;

		int lifetime;
		ParticleType type;

		bool still; // stationary

	public:
		Particle(float row1, float col1, ParticleType Type);


		int getRow() const;
		int getCol() const;
		float getXvel() const;
		float getYvel() const;
		ParticleType getType() const;
		bool isStill() const;
		int getLifetime() const;
		void getColor(uint8_t& red, uint8_t& green, uint8_t& blue) const;

		void setColor( uint8_t Red, uint8_t Green, uint8_t Blue);
		void setRow(float r, float c);
		void setStill(bool isStill);
		void setVel(float xval, float yval);
		void setLifetime(int frames); //amount of frames is supposed to exst for
		ParticleType setType(ParticleType newType);
	  // void(touch
		void Physics(World& World_Map);
};

#endif



