#include <iostream>
#include <string>
#include <regex>
#include "LinkedList.h"

#include "Stack.h"
#include "converter.h"

int main()
{
    try
    {
        //Char Array
        char prefix_in_string[30] = "* - + ^ 2.1 2 5.2 7.2 7.1";
        PostfixConverter converter(prefix_in_string);
        std::cout << "Postfix expression:" << converter.convertToPostfix() << std::endl;

        //String expression which can be entered by the user
        std::string prefix;
        std::cout << "Enter a prefix expression" << std::endl;
        std::getline(std::cin, prefix);
        
        //Removing multiple spaces if any
        std::regex space_re(R"(\s+)");
        prefix = std::regex_replace(prefix, space_re, " ");
        std::cout << "----Prefix Expression---- " << prefix << std::endl;
        PostfixConverter a(prefix);
        std::cout << a.convertToPostfix();
    }
    //When the exception is caught
    catch (const char *error)
    {
        std::cerr << error << std::endl;
    }
    return 0;
}