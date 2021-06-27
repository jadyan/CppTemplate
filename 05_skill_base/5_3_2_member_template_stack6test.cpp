/*
 * @Author: your name
 * @Date: 2021-06-15 15:56:32
 * @LastEditTime: 2021-06-15 15:57:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_3_2_member_template_stack6test.cpp
 */
/* The following code example is taken from the book
 * "C++ Templates - The Complete Guide"
 * by David Vandevoorde and Nicolai M. Josuttis, Addison-Wesley, 2002
 *
 * (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <string>
#include <vector>
#include "5_3_2_member_template_stack6.hpp"

int main()
{
    try {
        Stack<int>   intStack;       // stack of ints
        Stack<float> floatStack;     // stack of floats
        Stack<std::string, std::vector<std::string>> stringStack;

        // manipulate int stack
        intStack.push(42);
        intStack.push(7);

        // manipulate float stack
        floatStack.push(7.7);

        // assign stacks of different type
        floatStack = intStack;


        stringStack.push("jadyan");
        stringStack.push("anzhenrui");

        // print float stack
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
    }
    catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    // stack for ints using a vector as an internal container
    Stack<int,std::vector<int> > vStack;
    //...
    vStack.push(42);
    vStack.push(7);
    std::cout << vStack.top() << std::endl;
    vStack.pop();
}
