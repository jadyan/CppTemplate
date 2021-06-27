/*
 * @Author: your name
 * @Date: 2021-06-25 17:19:44
 * @LastEditTime: 2021-06-25 17:21:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_06_Template_parameters_and_member_templates/02/sumpolicy3.hpp
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
#ifndef SUMPOLICY_HPP
#define SUMPOLICY_HPP
/*
给SumPolicy添加一个Boolean型的非类型模板实参，从而可以选择是用 += 运算符来进行求和，还是只用 + 运算符来
进行求和。在这个例子中，
*/
#include <iostream>
using namespace std;

template<bool use_compound_op = true>
class SumPolicy {
  public:
    template<typename T1, typename T2>
    static void accumulate (T1& total, T2 const & value) {
        cout<<"+="<<endl;
        total += value;
    }
};

template<>
class SumPolicy<false> {
  public:
    template<typename T1, typename T2>
    static void accumulate (T1& total, T2 const & value) {
        cout<<" = *+*"<<endl;
        total = total + value;
    }
};

#endif // SUMPOLICY_HPP
