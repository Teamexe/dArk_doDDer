all:
	cd lib/getoptpp && make
	g++ -Wall -std=c++11 -I. main.cpp -c
	mv main.o bin/
	g++ -Wall -std=c++11 -I. keyname.cpp -c
	mv keyname.o bin/
	g++ -Wall -std=c++11 -I. util.cpp -c
	mv util.o bin/
	g++ -Wall -std=c++11 -o Logger bin/main.o bin/keyname.o \
	bin/util.o -L lib/getoptpp/bin/ -lgetoptpp
	mv Logger bin/
clean:
	rm bin/main.o bin/keyname.o bin/Logger bin/util.o
	cd lib/getoptpp && make clean
