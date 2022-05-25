
# default target
all: game

# driver is made by linking object files together
game: main.o System.o Character.o Player.o Enemy.o Item.o ItemHolder.o Weapon.o Armour.o
	g++ main.o System.o Character.o Player.o Enemy.o Item.o ItemHolder.o Weapon.o Armour.o -o game


System.o: System.cpp System.h
	g++ -c System.cpp -o System.o

Character.o: Character.cpp Character.h
	g++ -c Character.cpp -o Character.o


Player.o: Player.cpp Player.h
	g++ -c Player.cpp -o Player.o

Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp -o Enemy.o


Item.o: Item.cpp Item.h
	g++ -c Item.cpp -o Item.o

ItemHolder.o: ItemHolder.cpp ItemHolder.h
	g++ -c ItemHolder.cpp -o ItemHolder.o


Weapon.o: Weapon.cpp Weapon.h
	g++ -c Weapon.cpp -o Weapon.o

Armour.o: Armour.cpp Armour.h
	g++ -c Armour.cpp -o Armour.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

# clean removes all object files and the compiled executable
clean:
	rm -f *.o game
