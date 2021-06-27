/*
 * @Author: your name
 * @Date: 2021-06-03 15:16:09
 * @LastEditTime: 2021-06-03 15:19:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/01_basics/max5.cpp
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

// note: reference parameters
template <typename T>
inline T const& max (T const& a, T const& b)
{
    return  a < b  ?  b : a;
}



int main()
{
    std::string s;

    ::max("apple","peach");   // OK: same type
    /*
    由于长度的区别，这些字符串属于不同的数组类型。
    也就是说， ‘apple’ 和‘peach’ 具有相同的类型char const[6]； 然
    而‘tomato’的类型则是：char const[7]
    */
    //::max("apple","tomato");  // ERROR: different types
    //::max("apple",s);         // ERROR: different types

}
