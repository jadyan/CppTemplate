/*
 * @Author: your name
 * @Date: 2021-06-25 15:55:24
 * @LastEditTime: 2021-06-25 15:55:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_04_policy_policyclass/01/accum6.cpp
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
#include "accum6.hpp"
#include <iostream>
/*
在这个例子中，我们把policy实现为一个具有一个成员函数模板的
普通类（也就是说，类本身不是模板，而且该成员函数是隐式内联
的）。接下来我们还会讨论另一种实现方案。
通过给累积值指定一个不同的 policy，我们就可以进行不同的计
算
*/

int main()
{
    // create array of 5 integer values
    int num[] = { 1, 2, 3, 4, 5 };

    // print average value
    std::cout << "the average value of the integer values is "
              << Accum<int>::accum(&num[0], &num[5]) / 5
              << '\n';

    // create array of character values
    char name[] = "templates";
    int length = sizeof(name)-1;

    // (try to) print average character value
    std::cout << "the average value of the characters in \""
              << name << "\" is "
              << Accum<char>::accum(&name[0], &name[length]) / length
              << '\n';
}
