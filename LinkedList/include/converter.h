#pragma once

#include <iostream>
#include "Stack.h"

class PostfixConverter
{
    LinkedStack<std::string> stack;
    std::string prefix;

public:
    PostfixConverter(std::string prefix_expression) : prefix(prefix_expression) {}

    //to check the character is operator not
    bool isOperator(char character)
    {
        if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
        {
            return true;
        }
        return false;
    }

    //to check for spaces
    bool isSpace(char character)
    {
        return (character == ' ');
    }
    std::string convertToPostfix()
    {
        bool flag_for_space_found = false;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (isSpace(prefix[i]))
            {
                flag_for_space_found = true;
                break;
            }
        }
        std::string prefix_with_spaces;

        //If no spaces are found
        if (!flag_for_space_found)
        {
            for (int i = 0; i < prefix.length(); ++i)
            {
                prefix_with_spaces += prefix.substr(i, 1) + " ";
            }
            prefix = prefix_with_spaces;
        }

        LinkedStack<std::string> expression;
        prefix += " "; // for the better output
        int length = prefix.size();

        int without_space = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            if (isOperator(prefix[i]))
            {

                std::string op1 = expression.top();
                expression.pop();
                std::string op2 = expression.top();
                expression.pop();
                std::string temp;
                temp = op1 + op2 + prefix[i] + " ";

                expression.push(temp);
                i--;
            }
            else
            {

                if (isSpace(prefix[i]))
                {
                    //pushing from the index next to the current index till the next space's index
                    std::string to_push = prefix.substr(i + 1, without_space);
                    expression.push(to_push);
                    without_space = 0;
                }
                without_space++;
            }
        }
        std::cout << "****************************" << std::endl;
        std::string postfix = "";
        
        //Emptying the stack
        while (!(expression.isEmpty()))
        {

            postfix += expression.pop();
        }
        return postfix;
    }
};
