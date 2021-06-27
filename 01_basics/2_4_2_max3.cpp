/*
 * @Author: your name
 * @Date: 2021-06-03 14:39:00
 * @LastEditTime: 2021-06-03 14:43:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/01_basics/2_4_2_max3.cpp
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
#include <cstring>
#include <string>

using namespace std;

// maximum of two values of any type
template <typename T>
inline T const& max (T const& a, T const& b)
{
    cout<<"求两个任意类型值的最大者"<<endl;
    return  a < b  ?  b : a;
}

// maximum of two pointers
template <typename T>
inline T* const& max (T* const& a, T* const& b)
{
    cout<<"求两个指针所指向值的最大者"<<endl;
    return  *a < *b  ?  b : a;
}

// maximum of two C-strings
inline char const* const& max (char const* const& a,
                               char const* const& b)
{ 
    cout<<"求两个C字符串的最大者"<<endl;
    return  std::strcmp(a,b) < 0  ?  b : a;
}

int main ()
{
    cout<<"::max(a,b);=>"<<endl;
    int a=7;
    int b=42;
    ::max(a,b);      // max() for two values of type int

    cout<<"::max(s,t);=>"<<endl;
    std::string s="hey";
    std::string t="you";
    ::max(s,t);      // max() for two values of type std::string

    cout<<"::max(p1,p2);=>"<<endl;
    int* p1 = &b;
    int* p2 = &a;
    ::max(p1,p2);    // max() for two pointers

    cout<<"::max(s1,s2);=>"<<endl;
    char const* s1 = "David";
    char const* s2 = "Nico";
    ::max(s1,s2);    // max() for two C-strings
}
