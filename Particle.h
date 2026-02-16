#ifndef PARTICLE_H
#define PARTICLE_H

//#include
enum class ParticleType {
	AIR, 
	LIGHTNING,
	DIRT,
	EARTH,
	WATER,
	DUST,
	FIRE,
};

class Particle {
	private:
    float row, col;  // location
    
	ParticleType type;
    
	bool still; // stationary

	public:
	Particle(float row1, float col2, ParticleType Type);

	float getRow() const;
	float getCol() const;

	ParticleType getType() const;
	bool isStill() const;

	void setRow(float r, float c);
	void setStill(bool isStill);

};

#endif
 


