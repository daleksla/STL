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
	g++ $(LIB) $(STD) $(SOURCES)/linkedlistTest.cpp -o $(EXES)/linkedlistTest
	
	#testing strings
	g++ $(LIB) $(STD) $(SOURCES)/stringTest.cpp -o $(EXES)/stringTest
	
	#testing pointers
	g++ $(LIB) $(STD) $(SOURCES)/basepointerTest.cpp -o $(EXES)/basepointerTest
	g++ $(LIB) $(STD) $(SOURCES)/sharedpointerTest.cpp -o $(EXES)/sharedpointerTest
	g++ $(LIB) $(STD) $(SOURCES)/uniquepointerTest.cpp -o $(EXES)/uniquepointerTest
