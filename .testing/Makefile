# standard compile options for the c++ executable
STD = --std=c++17
LIB = -isystem /usr/include/c++/9/
WARN = -Wall

# deposit directories
SOURCES = ./sources
EXES = ./exes

# default super-target
all: 
	#testing stack
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/stackTest.cpp -o $(EXES)/stackTest
	
	#testing queue
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/queueTest.cpp -o $(EXES)/queueTest
	
	#testing linked list 
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/listTest.cpp -o $(EXES)/listTest
	
	#testing forward linked list 
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/fwdListTest.cpp -o $(EXES)/fwdListTest
	
	#testing vectors
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/vectorTest.cpp -o $(EXES)/vectorTest
	
	#testing arrays
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/arrayTest.cpp -o $(EXES)/arrayTest
	
	#testing strings
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/stringTest.cpp -o $(EXES)/stringTest
	
	#testing sorting algorithms
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/sortTest.cpp -o $(EXES)/sortTest
	
	#testing searching algorithms
	g++ $(LIB) $(STD) $(WARN) $(SOURCES)/searchTest.cpp -o $(EXES)/searchTest
