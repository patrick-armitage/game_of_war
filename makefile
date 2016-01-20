TITLE = gameOfWar
CPP = Game.cpp
CPP += Player.cpp
CPP += Die.cpp
CPP += LoadedDie.cpp
CPP += main.cpp
DELETE = *.gch
DELETE += *.o

all:
	g++ ${CPP} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
