all: build run


build:
	g++ -I ./include/ -o ./lib/KonsoldaGosterme.o -c ./src/KonsoldaGosterme.cpp
	g++ -I ./include/ -o ./lib/FileReading.o -c ./src/FileReading.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/SatirListesiNode.o -c ./src/SatirListesiNode.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesiNode.o -c ./src/YoneticiListesiNode.cpp

	g++ -I ./include/ -o ./bin/main ./lib/KonsoldaGosterme.o   ./lib/FileReading.o ./lib/SatirListesi.o ./lib/SatirListesiNode.o ./lib/YoneticiListesi.o  ./lib/YoneticiListesiNode.o   ./src/main.cpp

run:
	./bin/main