/*
 * @Author: your name
 * @Date: 2021-06-16 21:27:31
 * @LastEditTime: 2021-06-16 22:09:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/06_template_actual_combat/06_03_Separation_model/06_03_01_export/myfirst.cpp
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
#include <typeinfo>
#include "myfirst.hpp"

// implementation/definition of template

/*

https://blog.csdn.net/luoshabugui/article/details/86682360
https://www.cnblogs.com/gaoxianzhi/p/5723820.html
C++ Template》第六章讲过这个问题
组织模板代码有三种方式
1.包含模型（常规写法 将实现写在头文件中）
2.显式实例化（实现写在cpp文件中，使用template class语法进行显式实例化）
3.分离模型（使用C++ export关键字声明导出）

第三种方式理论最优，但是实际从C++标准提出之后主流编译器没有支持过，并且在最新的C++11标准中已经废除此特性，export关键字保留待用。
那么实际上能够使用的实现分离也就只有显式实例化

比较有意思的是，《C++ Template》书中作者建议代码为分离模型做准备，等待编译器支持之后替换，没想到最终这个特性被C++标准废弃了。
*/

export 
template <typename T>
void print_typeof (T const& x)
{
    std::cout << typeid(x).name() << std::endl;
}


//template void print_typeof<double>(double const &);
