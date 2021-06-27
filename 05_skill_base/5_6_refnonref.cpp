/*
 * @Author: your name
 * @Date: 2021-06-15 21:08:54
 * @LastEditTime: 2021-06-15 21:27:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_6_refnonref.cpp
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
#include <typeinfo>
#include <iostream>



template <typename T>
inline T const& ref_max (T const& a, T const& b)
{
    return a < b ? b : a;
}


void  ref_max_test()
{
    std::string s;
    ::ref_max("apple","peach"); // OK: 相同类型的实参
    //::ref_max("apple","tomato"); // ERROR: 不同类型的实参
    //::ref_max("apple",s); // ERROR: 不同类型的实参
}


template <typename T>
inline T nonref_max (T a, T b)
{
    return a < b ? b : a;
}
int nonref_max_test()
{
    std::string s;
    ::nonref_max("apple","peach"); // OK: 相同的类型
    ::nonref_max("apple","tomato"); // OK: 退化（decay）为相同的类型
    //::nonref_max("apple",s); // ERROR: 不同的类型
}


template <typename T>
void ref (T const& x)
{
    std::cout << "x in ref(T const&): "  
              << typeid(x).name() << '\n';
}

template <typename T>
void nonref (T x)
{
    std::cout << "x in nonref(T):     "
              << typeid(x).name() << '\n';
}

int main()
{
    ref_max_test();
std::cout<<"-------------------------------"<<std::endl;
    nonref_max_test();
std::cout<<"-------------------------------"<<std::endl;
    ref("hello");
    nonref("hello");
}
