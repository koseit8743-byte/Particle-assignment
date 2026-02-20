 #include "Colors.h"
#include "Particle.h"
 Color ParticleColor(ParticleType type){
    if (type == ParticleType::AIR){
     Color col = {255, 255, 255};
      return col;
     }
  
  else if (type == ParticleType::DUST){
       Color col = {200, 180, 130};
        return col;
     }

    else if (type == ParticleType::FIRE){
        Color col = {255, 90, 0};
       return col;
     }
  
    else if (type == ParticleType::WATER){
     Color col = {0, 90 , 255};
        return col;
      }
  
   else if (type == ParticleType::EARTH){
        Color col = {110, 65,33};
       return col;
     }
    else if (type == ParticleType::DIRT){
        Color col = {140, 65, 20};
        return col;
     }
   else if ( type == ParticleType::LIGHTNING){
    Color col = {255, 255, 0};
     return col;

   }

