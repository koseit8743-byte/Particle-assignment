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
-- touch() function to check if Particle is touching another
-- ParticleType function to set and get particle types
-- getters and setters in World.h for rows and columns
-- World_Map of chars
-- size() method to return how many particles are in the world
-- alive_count() method to see which particles lifetimes > 0
--Boundary method to see if the rows and Columns are set to the terminal_size()
--Wrote Makefile
# Particle Simulation Project

## Collaborators
- Kwabe
- Yousaf
- Diego



## COMPLETED WORK

### Kwabe 

#### Particle Class:
1. A Particle class with proper class design
2. Position (.row, .col float)
3. Velocity (.x_vel and .y_vel float)
4. .type enum (air, dust, fire, water, earth, dirt, lightning)
5. Each type has a different physics movement type
6. Air moves in a straight line (ignoring gravity) bouncing off solid
7. Dust has a small amount of gravity and randomly moves left and right every frame
8. Fire is stationary and shoots sparks of lightning in different directions over time
9. Water drips down and if it hits something solid it will slide sideways to find the lowest level
10. Earth is always stationary and solid
11. Lightning travels in a straight line and stops when it hits something solid
12. Dirt travels downwards and forms piles when it hits something solid
13. Color (.r .g .b uint8_t) set initially by type (fire = red, water = blue, etc.)
14. .stationary boolean
15. Stationary particles have lifetime of -1
16. .lifetime variable
17. Fire and lightning have short lifetimes, stone has lifetime -1
18. Member variables in private section
19. Methods in public section
20. Constructors, getters, setters (Rule of 0 followed)

### Colors System:
1. Created Colors.h with Color struct
2. Created ParticleColor() function for type-based colors

#### BRIDGES Visualization:
1. Read BRIDGES documentation
2. Added username and API key setup
3. Created ColorGrid class filled with world colors
4. Added bridges.setDataStructure() call
5. Added bridges.visualize() call
6. Implemented command to draw world on BRIDGES

--
### Yousaf - 
#### Particle Class:

1.physics() method with world map passed by reference
2. If particle runs into another particle, it calls .touch() on the other particle
3. Physics decrements .lifetime by one each frame

#### World Class:
1. World class with 2D grid of Particles
2. Size (.rows .cols) boundary of the world
3. Points leaving boundary are deleted
4. Map of chars indicating particle type at each location
5. std::list of Particles holding all particles
6. .at(row,col) method returning pointer to Particle (or nullptr)
7. .physics() method running through list and calling .physics() on each particle
8. Out of bounds particles deleted
9. Particles with lifetime = 0 deleted
10. .size() method returning number of particles
11. .alive_count() method returning particles with lifetime > 0
12. .save() method saving world state to disk
13. .load() method loading world state from disk
14. .touch() method for particle interactions
15. Between .physics and .touch handles all interactions (fire x water, water x lightning, etc.)

---

### Diego -

#### Game Class:
1.A Game class that is responsible for processing input - 
2.It has the world (.world World) as a member variable - 
3.The world should be initialized with the screen_size as the row and col, but leave some lines open on the bottom of the screen - 
4.A .frame member variable that starts at 0 and counts up by 1 each time physics is run -
5.It has to handle all input from mouse and keyboard using non-blocking I/O - 
6.Implement a command to start simulating the world - 
7. Implement a command to pause simulating the world - 
8.Implement a command to quit - 
9.Implement a command to load the world from disk -
10.Implement a command to save the world to disk - 
11.Implement a command to increase frame rate - 
12.Implement a command to decrease frame rate -
13.A .run() method that starts the game - 
14.On launch draw a splash screen -
15.Then go into an infinite loop of: handling user input, running physics, drawing the world, delaying - 
16.it should delay long enough to guarantee a fixed frame rate of 5 fps - 
17.Use clock (or std::chrono) to see how long it has been since the last frame began -
18.Use usleep() to delay execution so you get a guaranteed frame rate 
