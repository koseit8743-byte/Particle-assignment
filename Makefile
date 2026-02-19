#target: dependencies
a.out: main.o Particle.o World.o Game.o
	g++ main.o Particle.o World.o Game.o

main.o: main.cc Particle.h World.h Game.h
	g++ -c main.cc

Particle.o: Particle.cc Particle.h
	g++ -c Particle.cc

Game.o: Game.cc Game.h Particle.h
	g++ -c Game.cc

World.o: World.cc World.h Particle.h
	g++ -c World.cc

clean:
	rm -rf a.out main.o Particle.o World.o Game.o

