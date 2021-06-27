/*
 * @Author: your name
 * @Date: 2021-06-02 23:08:53
 * @LastEditTime: 2021-06-02 23:18:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/01_basics/max.cpp
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
#include "max.hpp"

int main()
{
    //两个int
/*
max()模板每次调用的前面都有域限定符 :: ，这是为了
确认我们调用的是全局名字空间中的max()。
*/
    int i = 42;
    std::cout << "max(7,i):   " << ::max(7,i) << std::endl;

//两个double
    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1,f2) << std::endl;

//两个std::string
    std::string s1 = "mathematics";
    std::string s2 = "math";
    std::cout << "max(s1,s2): " << ::max(s1,s2) << std::endl;
}
