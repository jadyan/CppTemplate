/*
 * @Author: your name
 * @Date: 2021-06-03 14:46:45
 * @LastEditTime: 2021-06-03 15:03:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/01_basics/2_4_3_max3.cpp
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
// maximum of two values of any type (call-by-reference)
template <typename T>
inline T const& max (T const& a, T const& b)
{
    cout<< "两个任意类型值的最大者 (通过传引用进行调用)" <<endl;
    return  a < b  ?  b : a;
}

// maximum of two C-strings (call-by-value)
inline char const* max (char const* a, char const* b)
{ 
    cout<<"两个C字符串的最大者 (通过传值进行调用) "<<endl;
    return  std::strcmp(a,b) < 0  ?  b : a;
}

// maximum of three values of any type (call-by-reference)
template <typename T>
inline T const& max (T const& a, T const& b, T const& c)
{

    cout<<"求3个任意类型值的最大者 (通过传引用进行调用) "<<endl;
    //return max (max(a,b), c);  // error, if max(a,b) uses call-by-value
    return ::max (::max(a,b), c);  // error, if max(a,b) uses call-by-value
}

int main ()
{
    ::max(7, 42, 68);     // OK

    const char* s1 = "frederic";
    const char* s2 = "anica";
    const char* s3 = "lucas";
    /*
    这是因为对于C-strings而言，这里的max(a,b)产生了一个新的临时局部值，该值有可能会被外面的max函数以传引用的方式返回，而这将导致传回无效的引用。
    return max (max(a,b), c);
    */
    ::max(s1, s2, s3);    // ERROR

}
