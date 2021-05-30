# standard compile options for the c++ executable
COMP ?= g++-10
STD ?= --std=c++2a
WARN = -Wall

# deposit directories
SOURCES = ./sources
EXES = ./exes

# default super-target
all: 
	#testing stack
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/stackTest.cpp -o $(EXES)/stackTest
	
	#testing queue
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/queueTest.cpp -o $(EXES)/queueTest
	
	#testing linked list 
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/listTest.cpp -o $(EXES)/listTest
	
	#testing forward linked list 
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/fwdListTest.cpp -o $(EXES)/fwdListTest
	
	#testing vectors
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/vectorTest.cpp -o $(EXES)/vectorTest
	
	#testing arrays
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/arrayTest.cpp -o $(EXES)/arrayTest
	
	#testing strings
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/stringTest.cpp -o $(EXES)/stringTest
	
	#testing sorting algorithms
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/sortTest.cpp -o $(EXES)/sortTest
	
	#testing searching algorithms
	$(COMP) $(LIB) $(STD) $(WARN) $(SOURCES)/searchTest.cpp -o $(EXES)/searchTest
