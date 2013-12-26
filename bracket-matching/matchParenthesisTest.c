#include "testUtils.h"
#include "matchParenthesis.h"

void test_matching_brackets_gives_1(){
        char expr[]="[i should pass as i am valid]";
        ASSERT(doBracketMatch(expr));
};
void test_gives_0_as_brackets_not_matched(){
        char expr[] = "i{am(not)correct}expression[";
        ASSERT(0 == doBracketMatch(expr));
};
void test_expression_with_valid_bracket_sequence_gives_1(){
        char expr[] = "{node(server[.{js}suraj]@)thoughtworks}";
        ASSERT(doBracketMatch(expr));
};
void test_expression_with_valid_brackets_sequence_gives_1(){
        char expr[] = "suraj(has(another{name}as)akshay);";
        ASSERT(doBracketMatch(expr));
};
void test_expression_without_brackets_gives_0(){
        char expr[] = "i_am_not_valid";
        ASSERT(doBracketMatch(expr));
};
void test_expression_with_incorrect_brackets_gives_0(){
        char data[] = "{some(where){broken?(yes)}";
        ASSERT(0 == doBracketMatch(data));
};