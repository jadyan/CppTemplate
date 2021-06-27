/*
 * @Author: your name
 * @Date: 2021-06-03 15:14:48
 * @LastEditTime: 2021-06-03 15:14:48
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/01_basics/max6.cpp
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

// note: nonreference parameters
template <typename T>
inline T max (T a, T b)
{
    return  a < b  ?  b : a;
}

int main()
{
    std::string s;

    ::max("apple","peach");   // OK: same type
	/*
 *
 *如果声明
的是非引用参数，你就可以使用长度不同的字符串来作为max()的参
数
 * */
    ::max("apple","tomato");  // OK: decays to same type
    //::max("apple",s);         // ERROR: different types
}
