#target: dependencies
a.out: main.o Particle.o World.o Game.o Colors_Local.o  NewBridges.o
	g++ main.o Particle.o World.o Game.o Colors_Local.o  NewBridges.o -lbridges -lcurl

main.o: main.cc Particle.h World.h Game.h Colors_Local.h
	g++ -c main.cc

Particle.o: Particle.cc Particle.h World.h
	g++ -c Particle.cc

Game.o: Game.cc Game.h Particle.h World.h Bridges.h
	g++ -c Game.cc

World.o: World.cc World.h Particle.h
	g++ -c World.cc

NewBridges.o: NewBridges.cc NewBridges.h
	g++ -c NewBridges.cc
Colors_Local.o: Colors_Local.cc Colors_Local.h
	g++ -c Colors_Local.cc


clean:
	rm -rf a.out main.o Particle.o World.o Colors_Local.o Game.o NewBridges.o
