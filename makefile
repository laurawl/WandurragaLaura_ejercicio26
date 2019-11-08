x.dat : ejer26.x
	./ejer26.x 

ejer26.x : ejer26.cpp
	c++ ejer26.cpp -o ejer26.x

clean :
	rm ejer26.x x.dat 