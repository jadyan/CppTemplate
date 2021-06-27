/*
 * @Author: your name
 * @Date: 2021-06-15 13:20:18
 * @LastEditTime: 2021-06-15 13:35:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/printcoll.hpp
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

// print elements of an STL container
//打印STL容器的元素
template <typename T>
void printcoll (T const& coll)
{
    //需要加上typename
    typename T::const_iterator pos;  // iterator to iterate over coll  用于迭代coll的迭代器 
    typename T::const_iterator end(coll.end());  // end position   结束位置

    for (pos=coll.begin(); pos!=end; ++pos)
    {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

