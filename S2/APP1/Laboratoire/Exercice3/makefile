

item_main: Item.o Item_simple.o Item_complexe.o main.o
	g++ -o item_main Item.o Item_simple.o Item_complexe.o main.o

main.o: main.cpp Item.h Item_simple.h Item_complexe.h
	g++ main.cpp -g -c

Item.o: Item.cpp Item.h
	g++ Item.cpp -g -c

Item_simple.o: Item_simple.cpp Item_simple.h
	g++ Item_simple.cpp -g -c

Item_complexe.o: Item_complexe.cpp Item_complexe.h Item_simple.h
	g++ Item_complexe.cpp -g -c

clean:
	rm -f *.o