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

//Check identity of the function
TEST_CASE("good input")
{
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));

    CHECK(nospaces(ariel::mat(1, 1, '!', '*')) == nospaces("!"));

    CHECK(nospaces(ariel::mat(7, 1, '@', '-')) == nospaces("@@@@@@@@@"));

    CHECK(nospaces(ariel::mat(1, 7, '^', '(')) == nospaces("^\n^\n^\n^\n^\n^\n^\n"));\

    CHECK(nospaces(ariel::mat(11, 3, '*', ')')) == nospaces("***********\n"
                                                            "*)))))))))*\n"
                                                            "***********"));

    CHECK(nospaces(ariel::mat(5, 3, '$', '&')) == nospaces("$$$$$\n"
                                                           "$&&&$\n"
                                                           "$$$$$"));

    CHECK(nospaces(ariel::mat(3, 3, '%', ' ')) == nospaces("%%%\n"
                                                            "%%\n"
                                                            "%%%"));
    //Check same sign
    CHECK(nospaces(ariel::mat(5, 3, '%', '%')) == nospaces("%%%%%\n"
                                                            "%%%%%\n"
                                                            "%%%%%"));                                                        

    CHECK(nospaces(ariel::mat(13, 9, '#', '!')) == nospaces("#############\n#!!!!!!!!!!!#\n#!#########!#\n#!#!!!!!!!#!#\n#!#!#####!#!#\n#!#!!!!!!!#!#\n#!#########!#\n#!!!!!!!!!!!#\n#############\n"));
}

TEST_CASE("Check first and last row"){

    string res = ariel::mat(5,3,'@','*');
    string first_row;
    for(int i=0;i<5;i++){
        first_row.push_back(res[i]);
    }    
    string last_row;
    int end = res.length();
    for(int i=end-2;i>end-7;i--){
        last_row.push_back(res[i]);
    }    
    // The first and last row supposed to by the same
    CHECK(nospaces(first_row) == nospaces(last_row)); 

    // Check now for more rows than cols
    string res2 = ariel::mat(1,7,'^','(');
    string first_row2;
    for(int i=0;i<1;i++){
        first_row2.push_back(res[i]);
    }    
    string last_row2;
    int end2 = res.length();
    for(int i=end2-2;i>end2-3;i--){
        last_row2.push_back(res[i]);
    }    
    CHECK(nospaces(first_row2) == nospaces(last_row2));                                                                                                                                      
}

// The output should be a palindrome
TEST_CASE("palindrome"){
    string ans;
    for(int i=1, j=3; i<11; i=i+2, j=j+2){
        ans = nospaces(ariel::mat(j,i,'#','-'));
        int len = ans.length();
        for(int k=0;k<len;k++){
            if(ans[k] != ans[len-k-1]){ //If the chars are different the input is not a palindrome
                FAIL_CHECK("False");
                break;
            }
        }
        cout << "Success\n";
    }

    // Check now for more rows
    string ans2;
    for(int i=3, j=1; j<11; i=i+2, j=j+2){
        ans = nospaces(ariel::mat(j,i,'#','-'));
        int len = ans.length();
        for(int k=0;k<len;k++){
            if(ans[k] != ans[len-k-1]){
                FAIL_CHECK("False");
                break;
            }
        }
        cout << "Success\n";
    }
}

//This should throw exception
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
    CHECK_THROWS(ariel::mat(-1,-1,'#','*'));







}