/*
 * @Author: your name
 * @Date: 2021-06-22 22:40:26
 * @LastEditTime: 2021-06-22 22:40:27
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/09_template_name/09_02_03_insert_name/inject.cpp
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

int C;

class C {
		private:
				int i[2]; 
	  public:
				static int f() { 
						return sizeof(C); 
				}
};

int f() 
{ 
		return sizeof(C); 
}


//从运行结果可以知道:成员函数C::f()返回类型C的大小;而函 数::f()返回变量C的大小(即int对象的大小)
int main() 
{
		std::cout << "C::f() = " << C::f() << ","
				<< " ::f() = " << ::f() << std::endl;
}
