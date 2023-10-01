//
// Created by Athan Johnson on 9/28/23.
//

#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"
#include "../reversed.cpp"

TEST_CASE( "Make sure that they really know when to stop reading" ) {
    char str[] = {'t', 'e', 's', 't'}; // there's no \n character to end this
    REQUIRE( reversed(str) == "tset" );
}

TEST_CASE( "Empty strings don't shatter everything" ) {
    REQUIRE( reversed("") == "" );
}

TEST_CASE( "Even length strings" ) {
    REQUIRE( reversed("at") == "ta" );
    REQUIRE( reversed("abcd") == "dcba" );
}

TEST_CASE( "Odd length strings" ) {
    REQUIRE( reversed("a") == "a");
    REQUIRE( reversed("abc") == "cba");
}

TEST_CASE( "Newline characters" ) {
    REQUIRE( reversed("te\nst") == "ts\net");
}

TEST_CASE( "Special characters" ) { // imo i don't think this is ever needed but idk if you made some super bad reversing function
    REQUIRE( reversed("&%\\\t*@") == "@*\t\\%&");
}