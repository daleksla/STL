/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#define private public
#define protected public

/* Include the code that we plan to test */
#include <lib/Types/string.hpp>
#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>
typedef Salih::Types::String String ;

/* Constructors */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

TEST_CASE("Empty Constructor - Attribute testing")
{
	String v ;
	REQUIRE(v.str[0] == '\0') ;
	REQUIRE(v.str != NULL) ;
}

TEST_CASE("const char* (c-string) Constructor - Attribute testing")
{
	String name("salih") ;
	REQUIRE(name.str[5] == '\0') ;
}

TEST_CASE("Copy Constructor - Attribute testing")
{
	String name("salih") ;
	String name2(name) ;
	String name3 = name ;
	REQUIRE(name2.str[5] == '\0') ;	
	REQUIRE(strcmp(name2.str, name.str) == 0) ;	
	REQUIRE(name3.str[5] == '\0') ;	
	REQUIRE(strcmp(name3.str, name.str) == 0) ;
	REQUIRE(name.str != NULL) ;	
	REQUIRE(name2.str != NULL) ;	
	REQUIRE(name3.str != NULL) ;		
}

TEST_CASE("Move Constructor - Attribute testing")
{
	String name2(String("salih")) ;
	REQUIRE(name2.str[5] == '\0') ;	
	REQUIRE(name2.str != NULL) ;		
}

TEST_CASE("Empty Constructor - Value testing")
{
	String v ;
	char* cmp = "" ;
	REQUIRE(v.size == 0) ;	
	REQUIRE(strcmp(v.str,cmp) == 0) ;	
}

TEST_CASE("const char* (c-string) Constructor - Value testing")
{
	String name("salih") ;
	char* cmp = "salih" ;
	REQUIRE(strcmp(name.str,cmp) == 0) ;
	REQUIRE(name.size == 5) ;		
}

TEST_CASE("Copy Constructor - Value testing")
{
	String name("salih") ;
	String name2(name) ;
	char* cmp = "salih" ;
	REQUIRE(strcmp(name.str,cmp) == 0) ;
	REQUIRE(strcmp(name2.str,cmp) == 0) ;
	REQUIRE(name.size == 5) ;
	REQUIRE(name2.size == 5) ;	
}

TEST_CASE("Move Constructor - Value testing")
{
	String name2(String("salih")) ;
	char* cmp = "salih" ;
	REQUIRE(strcmp(name2.str,cmp) == 0) ;
	REQUIRE(name2.size == 5) ;	
}

#pragma GCC diagnostic pop

/* Assignment operators */

TEST_CASE("assignment operator ('=') for a char*")
{}

TEST_CASE("assignment operator ('=') for a l-value (already created) String")
{}

TEST_CASE("assignment operator ('=') for a r-value (memory floating) String")
{}

/* Concat. operators */

TEST_CASE("addition operator ('+') for a char - testing value")
{}

TEST_CASE("addition operator ('+') for a char - testing memory")
{}

TEST_CASE("addition operator ('+') for a char* - testing value")
{}

TEST_CASE("addition operator ('+') for a char* - testing memory")
{}

TEST_CASE("addition operator ('+') for a String - testing value")
{}

TEST_CASE("addition operator ('+') for a String - testing memory")
{}

TEST_CASE("addition and replacement operator ('+=') for a char - testing value")
{}

TEST_CASE("addition and replacement operator ('+=') for a char - testing memory")
{}

TEST_CASE("addition and replacement operator ('+=') for a char* - testing value")
{}

TEST_CASE("addition and replacement operator ('+=') for a char* - testing memory")
{}

TEST_CASE("addition and replacement operator ('+=') for a String - testing value")
{}

TEST_CASE("addition and replacement operator ('+=') for a String - testing memory")
{}

/* general functions */

TEST_CASE("'getSize()' method - returns correct size")
{}

TEST_CASE("'getStr()' method - returns correct char*")
{}

