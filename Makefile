#target: dependencies
a.out: main.o Particle.o World.o Game.o colors.o  NewBridges.o
	g++ main.o Particle.o World.o Game.o colors.o  NewBridges.o -lbridges -lcurl

main.o: main.cc Particle.h World.h Game.h Colors.h
	g++ -c main.cc

Particle.o: Particle.cc Particle.h World.h
	g++ -c Particle.cc

Game.o: Game.cc Game.h Particle.h
	g++ -c Game.cc

World.o: World.cc World.h Particle.h
	g++ -c World.cc

NewBridges.o: NewBridges.cc NewBridges.h
	g++ -c NewBridges.cc
colors.o: colors.cc Colors.h
	g++ -c colors.cc


clean:
	rm -rf a.out main.o Particle.o World.o colors.o Game.o NewBridges.o
