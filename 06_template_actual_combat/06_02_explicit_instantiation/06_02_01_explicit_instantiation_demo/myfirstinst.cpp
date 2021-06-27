/*
 * @Author: your name
 * @Date: 2021-06-16 13:57:09
 * @LastEditTime: 2021-06-16 13:57:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/06_template_actual_combat/06_02_explicit_instantiation/06_02_01_explicit_instantiation_demo/myfirstinst.cpp
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
#include "myfirst.cpp"


/*

显式实例化指示符由关键字template和紧接其后的我们所需要实例
化的实体（可以是类、函数、成员函数等）的声明组成，而且，该声
明是一个已经用实参完全替换参数之后的声明。在我们的例子中，我
们针对的是一个普通函数，但该指示符也适用于成员函数和静态数据
成员。譬如：
//基于int显式实例化MyClass<>的构造函数
template MyClass<int>::MyClass();
//基于int显式实例化函数模板max()
template int const& max(int const&, int const&);
你还可以显式实例化类模板，这样就可以同时实例化它的所有类
成员。但有一点需要注意：对于这些在前面已经实例化过的成员，就
不能再次对它们进行实例化：
//基于int显式实例化类Stack<>
template class Stack<int>

*/
// explicitly instantiate print_typeof() for type double
template void print_typeof<double>(double const&);
