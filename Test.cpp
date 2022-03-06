#include "doctest.h"
#include "mat.hpp"
#include <stdexcept>
using namespace ariel;

#include <string>
#include <algorithm>

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("good input")
{
    CHECK(nospaces(ariel::mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK(nospaces(ariel::mat(1, 1, '!', '*')) == nospaces("!"));
    CHECK(nospaces(ariel::mat(1, 7, '@', '-')) == nospaces("@@@@@@@@@"));
    CHECK(nospaces(ariel::mat(7, 1, '^', '(')) == nospaces("^\n^\n^\n^\n^\n^\n^\n"));
    CHECK(nospaces(ariel::mat(11, 3, '*', ')')) == nospaces("***********\n*)))))))))*\n***********\n"));
    CHECK(nospaces(ariel::mat(5, 3, '$', '&')) == nospaces("$$$$$\n$&&&$\n$$$$$"));
    CHECK(nospaces(ariel::mat(3, 3, '%', ' ')) == nospaces("%%%%%%%%"));
    CHECK(nospaces(ariel::mat(13, 9, '#', '!')) == nospaces("#############\n#!!!!!!!!!!!#\n#!#########!#\n#!#!!!!!!!#!#\n#!#!#####!#!#\n#!#!!!!!!!#!#\n#!#########!#\n#!!!!!!!!!!!#\n#############\n"));
                                                          
}

TEST_CASE("bad input")
{
    CHECK_THROWS(ariel::mat(4,0,'#','$'));
    CHECK_THROWS(ariel::mat(3,0,'#','$'));
    CHECK_THROWS(ariel::mat(0,3,'#','$'));
    CHECK_THROWS(ariel::mat(0,0,'#','$'));
    CHECK_THROWS(ariel::mat(7,6,'_','#'));
    CHECK_THROWS(ariel::mat(6,7,'#','*'));
    CHECK_THROWS(ariel::mat(-1,3,'#','*'));
    CHECK_THROWS(ariel::mat(3,-1,'#','*'));
    CHECK_THROWS(ariel::mat(-1,-1,'#','*'));

}