CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

testGetCost: testGetCost.c dominion.o rngs.o
	gcc -o testGetCost -g testGetCost.c dominion.o rngs.o $(CFLAGS)

testisGameOver: testisGameOver.c dominion.o rngs.o
	gcc -o testisGameOver -g testisGameOver.c dominion.o rngs.o $(CFLAGS)

testGetWinners: testGetWinners.c dominion.o rngs.o
	gcc -o testGetWinners -g testGetWinners.c dominion.o rngs.o $(CFLAGS)

testAdventureFunc: testAdventureFunc.c dominion.o rngs.o
	gcc -o testAdventureFunc -g testAdventureFunc.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

runRandomTestAdventurer: randomtestadventurer.c dominion.o rngs.o
	./randomtestadventurer.exe > randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

runRandomTestCard1: randomtestcard1.c dominion.o rngs.o
	./randomtestcard1.exe > randomtestcard1.out
	gcov randomtestcard1 -b >> randomtestcard1.out

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

runRandomTestCard2: randomtestcard1.c dominion.o rngs.o
	./randomtestcard2.exe > randomtestcard2.out
	gcov randomtestcard2 -b >> randomtestcard2.out

testSmithyFunc: testSmithyFunc.c dominion.o rngs.o
	gcc -o testSmithyFunc -g testSmithyFunc.c dominion.o rngs.o $(CFLAGS)

testVillageFunc: testVillageFunc.c dominion.o rngs.o
	gcc -o testVillageFunc -g testVillageFunc.c dominion.o rngs.o $(CLAGS)

testGreatHallFunc: testGreatHallFunc.c dominion.o rngs.o
	gcc -o testGreatHallFunc -g testGreatHallFunc.c dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
