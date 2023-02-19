name = 2
make: $(name).cpp
	g++ -o matrice $(name).cpp

make cycle: $(name).cpp
	g++ -o matrice $(name).cpp
	.\matrice
	rm matrice.exe

make clean:
	rm matrice.exe