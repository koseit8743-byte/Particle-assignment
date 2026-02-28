<<<<<<< HEAD
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
-- .touch() function to see if the Particles are touching each other
(Update README with new .touch() function)

-- .touch() function to see if the Particles are touching each other
-- touch() function to check if Particle is touching another
 62687f1 (Update README with touch() function details)
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

Mythic_Bozo

 — 6:50 PM
Diego is this supposed to be colors.h ? I can't run main.cc because this thing is getting flagged. Also, I need to know what function to call right here
Image
Image
ᯓ diego ᯓ — 6:50 PM
no that was an old header i’m not using anymore
Mythic_Bozo

 — 6:50 PM
oh ok
ᯓ diego ᯓ — 6:50 PM
i think i’m having git trouble rn
Mythic_Bozo

 — 6:50 PM
oh shoot
ᯓ diego ᯓ — 6:51 PM
my game.h is showing an old instance
Mythic_Bozo

 — 6:51 PM
uhhh
search up the code to fix it, uh its kinda complex
ᯓ diego ᯓ — 6:52 PM
okay i hope this fixes if not i can just rewrite game.h real quick 🫩
Mythic_Bozo

 — 7:00 PM
Image
Try this
ᯓ diego ᯓ — 7:11 PM
working on it
ᯓ diego ᯓ — 8:04 PM
phew all fixed
yeah i had hella conflicts
Mythic_Bozo

 — 8:32 PM
alr
ill pull
ᯓ diego ᯓ — 8:33 PM
still working on game.cc should be good in 30 mins
Mythic_Bozo

 — 8:34 PM
k
after then lets hop into a vc so we can finish up and test stuff 
ill need all your changes Diego
Mythic_Bozo

 — 9:09 PM
lmk when your done Diego
ᯓ diego ᯓ — 9:17 PM
i’m almost done
Mythic_Bozo

 — 9:17 PM
oki dokie
@omwxbe do you wanna test it  then :?
omwxbe — 9:22 PM
yea try running it
if theres no erors run it
Mythic_Bozo

 — 9:22 PM
I need to pull Diego's code first cause I need to know how to call Game 
omwxbe — 9:22 PM
i ard turned it on canvas, diego if theres any other bullet points that you did you need to put it on read me
or just re submit it on canvas just add ur changes
Mythic_Bozo

 — 9:24 PM
we forgot to include the touch function in our Readme file
or idk
omwxbe — 9:25 PM
just add it
Mythic_Bozo

 — 9:25 PM
aight
you edited this right Kwabe :?
Image
yeah I won't be able to make until all the changes are finished
Mythic_Bozo

 — 9:35 PM
k imma shower lmk when its done
ᯓ diego ᯓ — 9:42 PM
okay i’m wrapped up im pushing rn
Mythic_Bozo

 — 10:04 PM
alr
we have oen error left
ᯓ diego ᯓ — 10:11 PM
in game?
Mythic_Bozo

 — 10:11 PM
ye I think I need a constructor rq for rows and columns :?
Image
ᯓ diego ᯓ — 10:14 PM
that’s my old instance did you pull?
Mythic_Bozo

 — 10:14 PM
yah I pulled rn.
lemme check the github
ill just swap it rq
ᯓ diego ᯓ — 10:14 PM
okay i hope i pushed right
fixing the conflicts sucked
Mythic_Bozo

 — 10:15 PM
your good, wait do we need this to be calling World :? I think yeah
Image
ᯓ diego ᯓ — 10:16 PM
yeah i think it would 
but i got rid of it
Mythic_Bozo

 — 10:16 PM
dam Idk whether to put it in my default constructor
wait Diego hop into call rq if you can
ᯓ diego ᯓ — 10:18 PM
hol up my computer just died
Mythic_Bozo

 — 10:18 PM
ooof
omwxbe — 10:21 PM
yeah i added more to the Read me
Mythic_Bozo

 — 10:21 PM
ok
imma test it out rn if you guys wanna join the vc
omwxbe — 10:21 PM
oh shoot i didnt push it
Mythic_Bozo

 — 10:25 PM
Diego is having toruble pushing
omwxbe — 10:36 PM
pushing what , i see all his changes
Mythic_Bozo

 — 10:39 PM
really? I have a divergent branch rn
wait liek you see everything in game
omwxbe — 10:41 PM
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
