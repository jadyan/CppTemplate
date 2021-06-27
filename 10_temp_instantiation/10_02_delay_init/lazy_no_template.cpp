/*
 * @Author: your name
 * @Date: 2021-06-23 15:17:41
 * @LastEditTime: 2021-06-23 15:55:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/10_temp_instantiation/10_02_delay_init/lazy.cpp
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



 
class Safe {
};


class Danger {
	public:
		typedef char Block[0];  // would fail for N<=0 如果N<=0的话 将会出错
};


/*
普通类一样 没用到也没有初始化
*/
class Tricky {
	public:
		virtual ~Tricky()
		{
		}
		void no_body_here( const Safe &safe);

		void inclass() 
		{ 
			Danger no_boom_yet;
		}
		//void error() { Danger<0> boom;}
		//void unsafe(T (*p)[N]);

		int*  operator->();

		//virtual Safe<T> suspect();
		struct Nested { 
			Danger pfew; 
		};
		union {  // anonymous union
			int align;
			Safe anonymous;
			//Danger<N>  anonymous;
		};
};

int main()
{
	Tricky ok;
}
