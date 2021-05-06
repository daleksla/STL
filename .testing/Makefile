# standard compile options for the c++ executable
STD = --std=c++17
LIB = -isystem /usr/include/c++/9/

# deposit directories
SOURCES = ./sources
EXES = ./exes

# default super-target
all: 
	#testing stack
	g++ $(LIB) $(STD) $(SOURCES)/stackTest.cpp -o $(EXES)/stackTest
	
	#testing queue
	g++ $(LIB) $(STD) $(SOURCES)/queueTest.cpp -o $(EXES)/queueTest
	
	#testing linked list 
	g++ $(LIB) $(STD) $(SOURCES)/listTest.cpp -o $(EXES)/listTest
	
	#testing strings
	g++ $(LIB) $(STD) $(SOURCES)/stringTest.cpp -o $(EXES)/stringTest
