/*
 * @Author: your name
 * @Date: 2021-06-15 15:11:45
 * @LastEditTime: 2021-06-15 15:22:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_3_member_template_stack5test.cpp
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
#include <cstdlib>
#include "5_3_member_stack5.hpp"

int main()
{
    try {
        Stack<int>   intStack;       // stack of ints
        Stack<float> floatStack;     // stack of floats
        Stack<std::string> stringStack; //stack of string 

        // manipulate int stack
        intStack.push(42);
        intStack.push(7);

        // manipulate float stack
        floatStack.push(7.7);


        //
        stringStack.push("jadyan");
        stringStack.push("anzhenrui");

        // assign stacks of different type
        //floatStack = intStack;
        intStack = floatStack;
/*
这个赋值并没有改变原栈的类型和它所含元素的类型。在
赋值以后，floatStack的元素仍然是float（浮点数）类型，因此它的top()
依然返回一个浮点数。
这个赋值函数好像屏蔽了类型检查，看起来你可以用任意类型的
栈来对目标栈[17]进行赋值；但实际情况并非如此，类型检查仍然存
在。当源栈（的拷贝）的元素被移入到目标栈的时候，就要执行必要
的类型检查，即类型检查发生在如下语句执行时：
elems.push_front(tmp.top());


例如，如果把一个字符串栈赋值给一个浮点数栈，那么编译器在
这一行将会报告一个错误信息，说明tmp.top()返回的字符串不能作为
elems.push_front()的实参（这个错误信息可能会根据编译器的不同而有
所不同，但大体意思就是这样）：
*/
        //intStack=stringStack;

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
        return EXIT_FAILURE;  // exit program with ERROR status
    }
}
