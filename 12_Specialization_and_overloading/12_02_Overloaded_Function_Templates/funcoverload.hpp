/*
 * @Author: your name
 * @Date: 2021-06-24 13:15:22
 * @LastEditTime: 2021-06-24 13:17:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_02_Overloaded_Function_Templates/funcoverload.hpp
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

using namespace std;
template<typename T> 
int f(T)
{ 
    cout<<"f(T)"<<endl;
    return 1;
}

template<typename T> 
int f(T*)
{ 
    cout<<"f(T*)"<<endl;
    return 2;
}
