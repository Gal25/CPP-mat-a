#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(3, 5, '#', '#')) == nospaces("###\n"
													 "###\n"
													 "###\n"
													 "###\n"
													 "###"));
	CHECK(nospaces(mat(9, 9, '@', '@')) == nospaces("@@@@@@@@@\n" //Simple rug - with the same char
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@"));												 	
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@"));
	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
													 "$+$\n"
													 "$+$\n"
													 "$+$\n"
													 "$$$"));
	CHECK(nospaces(mat(3, 5, '#', '+')) == nospaces("###\n"
													 "#+#\n"
													 "#+#\n"
													 "#+#\n"
													 "###"));
	CHECK(nospaces(mat(9, 7, '$', '-')) == nospaces("$$$$$$$$$\n"
													 "$-------$\n"
													 "$-$$$$$-$\n"
													 "$-$---$-$\n"
													 "$-$$$$$-$\n"
													 "$-------$\n"
													 "$$$$$$$$$"));	
	CHECK(nospaces(mat(9, 7, '-', '!')) == nospaces("---------\n"
													 "-!!!!!!!-\n"
													 "-!-----!-\n"
													 "-!-!!!-!-\n"
													 "-!-----!-\n"
													 "-!!!!!!!-\n"
													 "---------"));	
	CHECK(nospaces(mat(3, 5, '+', '$')) == nospaces("+++\n"
													 "+$+\n"
													 "+$+\n"
													 "+$+\n"
													 "+++"));
	CHECK(nospaces(mat(13, 5, '&', '-')) == nospaces("&&&&&&&&&&&&&\n"
													 "&-----------&\n"
													 "&-&&&&&&&&&-&\n"
													 "&-----------&\n"
													 "&&&&&&&&&&&&&"));
	CHECK(nospaces(mat(3, 5, '*', '+')) == nospaces("***\n"
													 "*+*\n"
													 "*+*\n"
													 "*+*\n"
													 "***"));
	CHECK(nospaces(mat(3, 5, '!', '+')) == nospaces("!!!\n"
													 "!+!\n"
													 "!+!\n"
													 "!+!\n"
													 "!!!"));
	CHECK(nospaces(mat(13, 9, '&', '-')) == nospaces("&&&&&&&&&&&&&\n"
													 "&-----------&\n"
													 "&-&&&&&&&&&-&\n"
													 "&-&-------&-&\n"
													 "&-&-&&&&&-&-&\n"
													 "&-&-------&-&\n"
													 "&-&&&&&&&&&-&\n"
													 "&-----------&\n"
													 "&&&&&&&&&&&&&"));
	CHECK(nospaces(mat(17,15, '&', '-')) == nospaces("&&&&&&&&&&&&&&&&&\n"
													 "&---------------&\n"
													 "&-&&&&&&&&&&&&&-&\n"
													 "&-&-----------&-&\n"
													 "&-&-&&&&&&&&&-&-&\n"
													 "&-&-&-------&-&-&\n"
													 "&-&-&-&&&&&-&-&-&\n"
													 "&-&-&-&---&-&-&-&\n"
													 "&-&-&-&&&&&-&-&-&\n"
													 "&-&-&-------&-&-&\n"
													 "&-&-&&&&&&&&&-&-&\n"
													 "&-&-----------&-&\n"
													 "&-&&&&&&&&&&&&&-&\n"
													 "&---------------&\n"
													 "&&&&&&&&&&&&&&&&&"));
	CHECK(nospaces(mat(13, 9, '#', '-')) == nospaces("#############\n"
													 "#-----------#\n"
													 "#-#########-#\n"
													 "#-#-------#-#\n"
													 "#-#-#####-#-#\n"
													 "#-#-------#-#\n"
													 "#-#########-#\n"
													 "#-----------#\n"
													 "#############"));
											 
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); //The row and column number is always odd
	CHECK_THROWS(mat(10, 8, '-', '%'));
	CHECK_THROWS(mat(0, -1, '$', '%'));
	CHECK_THROWS(mat(-1, 5, '$', '%'));
    CHECK_THROWS(mat(-2, 3, '$', '%'));
	CHECK_THROWS(mat(-1, -5, '$', '%')); //Both inputs must be positive
	CHECK_THROWS(mat(0, 0, '$', '%'));
	CHECK_THROWS(mat(4, 8, '$', '%'));

}
