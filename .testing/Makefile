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
	
	#testing forward linked list 
	g++ $(LIB) $(STD) $(SOURCES)/fwdListTest.cpp -o $(EXES)/fwdListTest
	
	#testing vectors
	g++ $(LIB) $(STD) $(SOURCES)/vectorTest.cpp -o $(EXES)/vectorTest
	
	#testing arrays
	g++ $(LIB) $(STD) $(SOURCES)/arrayTest.cpp -o $(EXES)/arrayTest
	
	#testing strings
	g++ $(LIB) $(STD) $(SOURCES)/stringTest.cpp -o $(EXES)/stringTest
	
	#testing sorting algorithms
	g++ $(LIB) $(STD) $(SOURCES)/sortTest.cpp -o $(EXES)/sortTest
	
	#testing searching algorithms
	g++ $(LIB) $(STD) $(SOURCES)/searchTest.cpp -o $(EXES)/searchTest
