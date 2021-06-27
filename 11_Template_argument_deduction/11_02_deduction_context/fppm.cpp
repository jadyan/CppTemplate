/*
 * @Author: your name
 * @Date: 2021-06-23 21:35:19
 * @LastEditTime: 2021-06-23 22:11:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/11_Template_argument_deduction/11_02_deduction_context/fppm.cpp
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

using  namespace std;

template <int N>
class X {
		public:
				typedef int I;
				void f(int i) {
            cout <<"i="<<N<<endl;
				}
};

/*
在函数模板fppm()中，子构造X<N>::I是一个不可演绎的上下文。 
然而，具有成员指针类型(即X<N>::*p)的成员类型部分X<N>是一个 可以演绎的上下文。于是，
可以根据这个可演绎上下文获得参数N，然 后把N放入不可演绎上下文X<N>::I，
就能够获得一个和实参&X<33>::f 匹配的类型。因此基于这个实参-参数对的演绎是成功的
*/

template<int N> 
void fppm(void (X<N>::*p)(typename X<N>::I))
{

		cout<<"fppm(void (X<N>::*p)(typename X<N>::I)) 函数"<<endl;
}

int main() 
{
		fppm(&X<33>::f);  // fine: N deduced to be 33
}
