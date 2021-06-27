/*
 * @Author: your name
 * @Date: 2021-06-25 10:32:13
 * @LastEditTime: 2021-06-25 10:40:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/13_template_polymorphism/13_05_Generic_Programming/printmax.cpp
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
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "MyClass.hpp"

template <typename T>
void print_max (T const& coll)
{
    // declare local iterator of collection
    //// 声明一个局部的容器迭代器
    typename T::const_iterator pos;

    // compute position of maximum value
    //// 计算出最大值的位置
    pos = std::max_element(coll.begin(),coll.end());

    // print value of maximum element of coll (if any):
    ////输出容器coll的最大元素的值（如果存在的话）
    if (pos != coll.end()) {
        std::cout << *pos << std::endl;
    }
    else {
        std::cout << "empty" << std::endl;
    }
}

/*
STL借助于迭代器对这些操作进行了参数化，从而避免了操作定义
在数量上的过度膨胀。在此，你并不需要为每个容器都实现每一个操
作，只需要实现某个算法一次，就可以把该算法应用到每个容器中。
换句话说，泛型程序设计的“粘合剂”就是：由容器提供的并且能被算
法所使用的迭代器。迭代器之所以能够肩负这样的任务，是由于容器
为迭代器提供了一些特定的接口，而算法所使用的正是这些接口。我
们通常也把每个这样的接口称为一个concept （即约束），它说明一个
模板（即容器）如果要并入这个框架（即 STL），就必须履行或者实
现这些约束。
从原则上讲，也可以使用动多态来实现这些类似于 STL 的功能。
然而，用多态实现的功能使用起来肯定会很受限制，因为与迭代器的
概念相比，动多态的虚函数调用机制将会是一种重量级的实现机制，
这就会对效率产生很大的影响。譬如增加一层基于虚函数的接口层，
通常就会影响操作的效率，而且这种影响的程度可能是几个数量级的
（甚至更加严重）。
事实上，泛型程序设计是相当实用的，因为它所依赖的是静多
态，而静多态会要求在编译期对接口进行解析。另一方面，这种要求
（即对接口在编译期进行解析）还会带来一些与面向对象程序设计原
则截然不同的新设计原则，在本书的剩余部分我们将会阐述许多重要
的泛型设计原则。
*/

int main()
{
    std::vector<MyClass> c1;
    std::list<MyClass>   c2;
    //...
    c1.push_back(MyClass(18));
    c1.push_back(MyClass(27));
    c1.push_back(MyClass(15));
    c1.push_back(MyClass(19));
    print_max (c1);
std::cout<<"-----list----"<<std::endl;
    c2.push_back(MyClass(10));
    c2.push_back(MyClass(15));
    c2.push_back(MyClass(88));
    c2.push_back(MyClass(3));
    print_max (c2);
}
