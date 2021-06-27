/*
 * @Author: your name
 * @Date: 2021-06-09 21:49:28
 * @LastEditTime: 2021-06-09 21:49:28
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/03_classtemplate/3_5_defult_para_template_stack3.cpp
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
#include <deque>
#include <cstdlib>
#include "3_5_defult_para_template_stack3.hpp"

int main()
{
    try {
        // stack of ints:  使用缺省值vetor
        Stack<int> intStack;

        // stack of doubles which uses a std::deque<> to manage the elements 不使用缺省值，使用deque
        Stack<double,std::deque<double> > dblStack;

        // manipulate int stack
        intStack.push(7);
        std::cout << intStack.top() << std::endl;
        intStack.pop();

        // manipulate double stack
        dblStack.push(42.42);
        std::cout << dblStack.top() << std::endl; 
        dblStack.pop();
        dblStack.pop();
    }
    catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;  // exit program with ERROR status
    }
}
