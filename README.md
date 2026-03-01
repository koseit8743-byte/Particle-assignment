# Particle-assignment
Class group, the giggles , particle assignment

Kwabe: 
Position (.row, .col float)
Velocity (.x_vel and .y_vel float)
.type enum (air, dust, fire, water, earth, dirt, lightning)
Color (.r .g .b uint8_t) that should be set initially by its type
.stationary boolean
.lifetime variable
Member variables in private section
Methods in public section
Constructor with parameters
Getters for all member variables (getRow, getCol, getXvel, getYvel, getType, isStill, getLifetime, getColor)
Setters for all member variables (setRow, setStill, setVel, setLifetime, setColor)
Rule of 0 followed
 Created Colors.h with Color struct
Created Colors.cc with ParticleColor() function
Integrated colors into Particle constructor
Set default colors for each particle type (AIR=white, DUST=tan, FIRE=orange, WATER=blue, EARTH=brown, DIRT=dark brown, LIGHTNING=yellow)

Yousaf:
-- created a size of rows and cols of the boundary of the world
--List of all particles in the world
-- Lifetime variable that decrements over time 
-- setStill function to check if particle is moving
-- .touch() function to see if the Particles are touching each other
-- ParticleType function to set and get particle types
-- getters and setters in World.h for rows and columns
-- World_Map of chars
-- size() method to return how many particles are in the world
-- alive_count() method to see which particles lifetimes > 0
--Boundary method to see if the rows and Columns are set to the terminal_size()
--Wrote Makefile



Diego:
--It has the world (.world World) as a member variable
 ----The world should be initialized with the screen_size as the row and col, but leave some lines open on the bottom of the screen to show the frame count and a helpful list of commands
  --It has to handle all input from mouse and keyboard using non-blocking I/O
--Implement a command to start simulating the world
--Implement a command to pause simulating the world
--Implement a command to quit
 --Implement a command to load the world from disk
 --Implement a command to save the world to disk 
and ----Use clock (or std::chrono) to see how long it has been since the last frame began
