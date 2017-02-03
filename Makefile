all:
	cd lib/getoptpp && make
	g++ -Wall -std=c++11 -I. main.cpp -c
	g++ -Wall -std=c++11 -I. keyname.cpp -c
	g++ -Wall -std=c++11 -o Logger main.o keyname.o
clean:
	rm main.o keyname.o Logger
	cd lib/getoptpp && make clean
