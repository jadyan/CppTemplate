/*
 * @Author: your name
 * @Date: 2021-06-24 14:09:57
 * @LastEditTime: 2021-06-24 14:11:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_02_04_template_and_not_template/nontmpl.cpp
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
#include <string>
#include <iostream>

/*
12.2.4 模板和非模板
函数模板也可以和非模板函数同时重载。当其它的所有条件都是
一样的时候，实际的函数调用将会优先选择非模板函数。下面的例子
说明了这一点：

*/
template<typename T> 
std::string f(T) 
{ 
    return "Template"; 
}

std::string f(int&) 
{ 
    return "Nontemplate"; 
}

int main() 
{
    int x = 7;
    std::cout << f(x) << std::endl;
}
