/*
 * @Author: your name
 * @Date: 2021-06-03 14:11:34
 * @LastEditTime: 2021-06-03 14:36:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/01_basics/max2.cpp
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

using namespace std;
// maximum of two int values
//求两个int值的最大值
inline int const& max (int const& a, int const& b) 
{
    cout<<"max求两个int值的最大值"<<endl;
    return  a < b ? b : a;
}

// maximum of two values of any type
// 求两个任意类型值中的最大者
template <typename T>
inline T const& max (T const& a, T const& b)
{
    cout<<"max求两个任意类型值中的最大者"<<endl;
    return  a < b ? b : a;
}

// maximum of three values of any type
// 求3个任意类型值中的最大者
template <typename T>
inline T const& max (T const& a, T const& b, T const& c)
{
    cout<<"max求3个任意类型值中的最大者"<<endl;
    return ::max (::max(a,b), c);
}

int main()
{
    cout<<"::max(7, 42, 68);=>"<<endl;
    ::max(7, 42, 68);     // calls the template for three arguments  // 调用具有3个参数的模板

    cout<<"::max(7.0, 42.0);=>"<<endl;
    ::max(7.0, 42.0);     // calls max<double> (by argument deduction)

    cout<<"::max('a', 'b');=>"<<endl;
    ::max('a', 'b');      // calls max<char> (by argument deduction)

    cout<<"::max(7, 42); =>"<<endl;
    ::max(7, 42);         // calls the nontemplate for two ints

cout<<"----显式地指定一个空的模板实参列表，这个语法好像是告诉编译器：只有模板才能来匹配这个调用，而且所有的模板参数都应该根据调用实参演绎出来 ---"<<endl;
    cout<<"::max<>(7, 42);  =>"<<endl;
    ::max<int>(7, 42);       // calls max<int> (by argument deduction)
cout<<"-------"<<endl;

    cout<<"::max<double>(7, 42);  =>"<<endl;
    ::max<double>(7, 42); // calls max<double> (no argument deduction)

    cout<<"::max('a', 42.7);   =>"<<endl;
    ::max('a', 42.7);     // calls the nontemplate for two ints
}
