all:
	cd lib/getoptpp && make
	g++ -Wall -std=c++11 -I. main.cpp -c
	g++ -Wall -std=c++11 -I. keyname.cpp -c
	g++ -Wall -std=c++11 -I. util.cpp -c
	g++ -Wall -std=c++11 -o Logger main.o keyname.o util.o -L lib/getoptpp/bin/ -lgetoptpp
clean:
	rm main.o keyname.o Logger util.o
	cd lib/getoptpp && make clean
