/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#define private public
#define protected public

/* Include the code that we plan to test */
#include "../../containers/string.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>
typedef salih::containers::String String ;

/* Constructors */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

TEST_CASE("Empty Constructor - Attribute testing")
{
	String v ;
	REQUIRE(v.str[0] == '\0') ;
	REQUIRE(v.str != NULL) ;
}

TEST_CASE("size initialisation Constructor - Attribute testing")
{
	String name(2) ;
	REQUIRE(name.str[2] == '\0') ;
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

/* Assignment operators */

TEST_CASE("(value) assignment operator ('=') for a char*")
{
	String v ;
	v = "salih" ;
	char* val = "salih" ;
	REQUIRE(strcmp(v.str,val) == 0) ;
	String a = "yusuf" ;
	char* val2 = "yusuf" ;
	REQUIRE(strcmp(a.str,val2) == 0) ;
}

TEST_CASE("(value) assignment operator ('=') for a l-value (already created) String")
{
	String v ;
	String a("salih") ;
	v = a ;
	char* val = "salih" ;
	REQUIRE(strcmp(a.str,val) == 0) ;	
	REQUIRE(strcmp(v.str,a.str) == 0) ;	
}

TEST_CASE("(value) assignment operator ('=') for a r-value (memory floating) String")
{
	String v ;
	v = String("salih") ;
	char* val = "salih" ;
	REQUIRE(strcmp(v.str,val) == 0) ;		
}

/* Concat. operators */

TEST_CASE("addition operator ('+') for a char - testing value")
{
	String v("salih") ;
	String w = v + 'b' ;
	char* val = "salihb" ;
	REQUIRE(strcmp(w.str, val) == 0) ;
}

TEST_CASE("addition operator ('+') for a char - testing memory")
{
	String v("salih") ;
	String w = v + 'b' ;
	REQUIRE(&w != &v) ;
}

TEST_CASE("addition operator ('+') for a char* - testing value")
{
	String v("salih") ;
	String w = v + "b" ;
	char* val = "salihb" ;
	REQUIRE(strcmp(w.str, val) == 0) ;
}

TEST_CASE("addition operator ('+') for a char* - testing memory")
{
	String v("salih") ;
	String w = v + "b" ;
	REQUIRE(&w != &v) ;
}

TEST_CASE("addition operator ('+') for a String - testing value")
{
	String v("salih"), b("balih") ;
	String w = v + b ;
	char* val = "salihbalih" ;
	REQUIRE(strcmp(w.str, val) == 0) ;
}

TEST_CASE("addition operator ('+') for a String - testing memory")
{
	String v("salih"), b("balih") ;
	String w = v + b ;
	REQUIRE(((&w != &v) && (&w != &b))) ;
}

TEST_CASE("addition and replacement operator ('+=') for a char - testing value")
{
	String v("salih") ;
	v += 'b' ;
	char* val = "salihb" ;
	REQUIRE(strcmp(v.str, val) == 0) ;	
}

TEST_CASE("addition and replacement operator ('+=') for a char - testing memory")
{
	String v("salih") ;
	auto beforeV = &v ;
	v += 'b' ;
	REQUIRE(beforeV == &v) ;
}

TEST_CASE("addition and replacement operator ('+=') for a char* - testing value")
{
	String v("salih") ;
	v += "b" ;
	char* val = "salihb" ;
	REQUIRE(strcmp(v.str,val) == 0) ;
}

TEST_CASE("addition and replacement operator ('+=') for a char* - testing memory")
{
	String v("salih") ;
	String* beforeV = &v ;
	v += "b" ;
	REQUIRE(beforeV == &v) ;
}

TEST_CASE("addition and replacement operator ('+=') for a String - testing value")
{	
	String v("salih"), b("balih") ;
	v += b ;
	char* val = "salihbalih" ;
	REQUIRE(strcmp(v.str, val) == 0) ;
}

TEST_CASE("addition and replacement operator ('+=') for a String - testing memory")
{
	String v("salih"), b("balih") ;
	auto beforeV = &v ;
	v += b ;
	REQUIRE(&v == beforeV) ;
}

/* multiplication operators */

TEST_CASE("multiplication operator ('*') for a String - testing value")
{
	String v("salih") ;
	String w = v * 2 ;
	char* val = "salihsalih" ;
	REQUIRE(strcmp(w.str, val) == 0) ;
}

TEST_CASE("multiplication operator ('*') for a String - testing memory")
{
	String v("salih") ;
	String w = v * 2 ;
	REQUIRE(&w != &v) ;
}

TEST_CASE("multiplication and replacement operator ('*=') for a char - testing value")
{
	String v("salih") ;
	v *= 2 ;
	char* val = "salihsalih" ;
	REQUIRE(strcmp(v.str, val) == 0) ;	
}

TEST_CASE("multiplication and replacement operator ('*=') for a char - testing memory")
{
	String v("salih") ;
	auto beforeV = &v ;
	v *= 2 ;
	REQUIRE(beforeV == &v) ;
}

/* general functions */

TEST_CASE("'getSize()' method - returns correct size")
{
	String v ;
	REQUIRE(v.getSize() == 0) ;
	REQUIRE(v.size == v.getSize()) ;
	String v2("balih") ;
	REQUIRE(v2.getSize() == 5) ;
	REQUIRE(v2.size == v2.getSize()) ;
}

TEST_CASE("'get()' method - returns correct char*")
{
	String v ;
	char* val = "" ;
	REQUIRE(strcmp(val,v.get()) == 0) ;
	REQUIRE(v.str == v.get()) ;
	
	String v2("balih") ;
	char* val2 = "balih" ;
	REQUIRE(strcmp(val2,v2.get()) == 0) ;
	REQUIRE(v2.str == v2.get()) ;
}

/* String value checking functions */

TEST_CASE("'isUpper()' method - returns correct value")
{
	String v ;
	REQUIRE(v.isUpper() == false) ;
	String a("balih") ;
	REQUIRE(a.isUpper() == false) ;
	String b("Talih") ;
	REQUIRE(b.isUpper() == false) ;
	String c("SALIH") ;
	REQUIRE(c.isUpper() == true) ;
}

TEST_CASE("'isLower()' method - returns correct value")
{
	String v ;
	REQUIRE(v.isLower() == false) ;
	String a("balih") ;
	REQUIRE(a.isLower() == true) ;
	String b("Talih") ;
	REQUIRE(b.isLower() == false) ;
	String c("SALIH") ;
	REQUIRE(c.isLower() == false) ;
}

TEST_CASE("'isCapitalised()' method - returns correct value")
{
	String v ;
	REQUIRE(v.isCapitalised() == false) ;
	String a("balih") ;
	REQUIRE(a.isCapitalised() == false) ;
	String b("Talih") ;
	REQUIRE(b.isCapitalised() == true) ;
	String c("SALIH") ;
	REQUIRE(c.isCapitalised() == false) ;
}

/* String value manipulation functions */

TEST_CASE("'upper()' method - returns correct value")
{
	String v ;
	REQUIRE(strcmp(v.upper().str, "") == 0) ;
	String a("balih") ;
	REQUIRE(strcmp(a.upper().str, "BALIH") == 0) ;
	String b("Talih") ;
	REQUIRE(strcmp(b.upper().str, "TALIH") == 0) ;
	String c("SALIH") ;
	REQUIRE(strcmp(c.upper().str, "SALIH") == 0) ;
}

TEST_CASE("'lower()' method - returns correct value")
{
	String v ;
	REQUIRE(strcmp(v.lower().str, "") == 0) ;
	String a("balih") ;
	REQUIRE(strcmp(a.lower().str, "balih") == 0) ;
	String b("Talih") ;
	REQUIRE(strcmp(b.lower().str, "talih") == 0) ;
	String c("SALIH") ;
	REQUIRE(strcmp(c.lower().str, "salih") == 0) ;
}

TEST_CASE("'capitalise()' method - returns correct value")
{
	String v ;
	REQUIRE(strcmp(v.capitalise().str, "") == 0) ;
	String a("balih") ;
	REQUIRE(strcmp(a.capitalise().str, "Balih") == 0) ;
	String b("Talih") ;
	REQUIRE(strcmp(b.capitalise().str, "Talih") == 0) ;
	String c("SALIH") ;
	REQUIRE(strcmp(c.capitalise().str, "Salih") == 0) ;
}
//
/* iterators */
TEST_CASE("Iterator object - empty initialisation")
{
	String str(6) ;
	REQUIRE(String::Iterator().pointer == nullptr) ;
}

TEST_CASE("Iterator object - prefix incrementation")
{
	String str(6) ;
	auto it = str.begin() ;
	REQUIRE(++it == String::Iterator(&(str[1]))) ;
	REQUIRE(it == String::Iterator(&(str[1]))) ;
}

TEST_CASE("Iterator object - postfix incrementation")
{
	String str(6) ;
	auto it = str.begin() ;
	REQUIRE(it++ == String::Iterator(&(str[0]))) ;
	REQUIRE(it++ == String::Iterator(&(str[1]))) ;
}

TEST_CASE("Iterator object - moving position using + operator (addition)")
{
	String str(6) ;
	auto it = str.begin() ;
	REQUIRE((it+1) == String::Iterator(&(str[1]))) ;
	REQUIRE((it) == String::Iterator(&(str[0]))) ;
}

TEST_CASE("Iterator object - moving position using += operator (compound addition)")
{
	String str(6) ;
	auto it = str.begin() ;
	REQUIRE((it+=1) == String::Iterator(&(str[1]))) ;
	REQUIRE(it == String::Iterator(&(str[1]))) ;
}

TEST_CASE("Iterator object - prefix decrement")
{
	String str(6) ;
	auto it = str.end() ;
	REQUIRE(--it == String::Iterator(&(str[5]))) ;
}

TEST_CASE("Iterator object - postfix decrement")
{
	String str(6) ;
	auto it = str.end() ;
	REQUIRE(it-- == String::Iterator(&(str[6]))) ;
}

TEST_CASE("Iterator object - moving position using - operator (subtracting)")
{
	String str(6) ;
	auto it = str.end() ;
	REQUIRE(it-1 == String::Iterator(&(str[5]))) ;
	REQUIRE(it == String::Iterator(&(str[6]))) ;
}

TEST_CASE("Iterator object - moving position using -= operator (compound subtracting)")
{
	String str(6) ;
	auto it = str.end() ;
	REQUIRE((it-=1) == String::Iterator(&(str[5]))) ;
	REQUIRE(it == String::Iterator(&(str[5]))) ;
}

TEST_CASE("Iterator object - equality comparison")
{
	String str(6) ;
	auto it = str.end() ;
	REQUIRE(it == str.end()) ;
	it = str.begin() ;
	REQUIRE(it == str.begin()) ;
}

TEST_CASE("Iterator object - inequality comparison")
{
	String str(6) ;
	auto it = str.begin() ;
	REQUIRE(it != str.end()) ;
	it = str.end() ;
	REQUIRE(it != str.begin()) ;
}

TEST_CASE("Iterator object - dereferencing operator")
{
	String str{"saliha"} ;
	auto it = str.begin() ;
	REQUIRE(*it == 's') ;
}

/* const iterators */
TEST_CASE("ConstIterator object - empty initialisation")
{
	String str(6) ;
	REQUIRE(String::ConstIterator().pointer == nullptr) ;
}

TEST_CASE("ConstIterator object - prefix incrementation")
{
	String str(6) ;
	auto it = str.cbegin() ;
	REQUIRE(++it == String::ConstIterator(&(str[1]))) ;
	REQUIRE(it == String::ConstIterator(&(str[1]))) ;
}

TEST_CASE("ConstIterator object - postfix incrementation")
{
	String str(6) ;
	auto it = str.cbegin() ;
	REQUIRE(it++ == String::ConstIterator(&(str[0]))) ;
	REQUIRE(it++ == String::ConstIterator(&(str[1]))) ;
}

TEST_CASE("ConstIterator object - moving position using + operator (addition)")
{
	String str(6) ;
	auto it = str.cbegin() ;
	REQUIRE(it+1 == String::ConstIterator(&(str[1]))) ;
	REQUIRE(it == String::ConstIterator(&(str[0]))) ;
}

TEST_CASE("ConstIterator object - moving position using += operator (compound addition)")
{
	String str(6) ;
	auto it = str.cbegin() ;
	REQUIRE((it+=1) == String::ConstIterator(&(str[1]))) ;
	REQUIRE(it == String::ConstIterator(&(str[1]))) ;
}

TEST_CASE("ConstIterator object - prefix decrement")
{
	String str(6) ;
	auto it = str.cend() ;
	REQUIRE(--it == String::ConstIterator(&(str[5]))) ;
}

TEST_CASE("ConstIterator object - postfix decrement")
{
	String str(6) ;
	auto it = str.cend() ;
	REQUIRE(it-- == String::ConstIterator(&(str[6]))) ;
}

TEST_CASE("ConstIterator object - moving position using - operator (subtracting)")
{
	String str(6) ;
	auto it = str.cend() ;
	REQUIRE((it-1) == String::ConstIterator(&(str[5]))) ;
	REQUIRE(it == String::ConstIterator(&(str[6]))) ;
}

TEST_CASE("ConstIterator object - moving position using -= operator (compound subtracting)")
{
	String str(6) ;
	auto it = str.cend() ;
	REQUIRE((it-=1) == String::ConstIterator(&(str[5]))) ;
	REQUIRE(it == String::ConstIterator(&(str[5]))) ;
}

TEST_CASE("ConstIterator object - equality comparison")
{
	String str(6) ;
	auto it = str.cend() ;
	REQUIRE(it == str.cend()) ;
	it = str.cbegin() ;
	REQUIRE(it == str.cbegin()) ;
}

TEST_CASE("ConstIterator object - inequality comparison")
{
	String str(6) ;
	auto it = str.cbegin() ;
	REQUIRE(it != str.cend()) ;
	it = str.cend() ;
	REQUIRE(it != str.cbegin()) ;
}

TEST_CASE("ConstIterator object - dereferencing operator")
{
	String str{"saliha"} ;
	auto it = str.cbegin() ;
	REQUIRE(*it == 's') ;
}

#pragma GCC diagnostic pop
