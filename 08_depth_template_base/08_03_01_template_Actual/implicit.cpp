/*
 * @Author: your name
 * @Date: 2021-06-22 15:37:04
 * @LastEditTime: 2021-06-22 15:48:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/08_depth_template_base/08_03_01_template_Actual/implicit.cpp
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

 /*
 第一个为返回值类型时候，调用是只需要指定返回值类型，其他的自动推导 
 */
template <typename DstT, typename SrcT>
inline DstT implicit_cast (SrcT const& x)  // SrcT can be deduced,
{                                          // but DstT cannot
    return x;
}


 /*
 第一个不是返回值类型时候，调用时候，必须全部指出
 */
template <typename SrcT, typename DstT>
inline DstT implicit_cast2 (SrcT const& x)  // SrcT can be deduced,
{                                          // but DstT cannot
    return x;
}


int main()
{
    //double value = implicit_cast<double>(-1);
    cout<<"implicit_cast<double>(-1) = "<<implicit_cast<double>(-1)<<endl;
    //double value2 = implicit_cast2<double, double>(-1);
    cout<<"implicit_cast2<double, double>(-1) = "<<implicit_cast2<double,double>(-1)<<endl;
}
