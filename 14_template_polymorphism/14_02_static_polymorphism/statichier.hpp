/*
 * @Author: your name
 * @Date: 2021-06-25 09:50:49
 * @LastEditTime: 2021-06-25 09:51:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/13_template_polymorphism/13_02_static_polymorphism/statichier.hpp
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
#include "coord.hpp"

using namespace std;
// concrete geometric object class Circle
// - \bfseries not derived from any class
class Circle {
  public:
		virtual void draw() const
		{
			cout<<"Circle:: draw() 函数"<<endl;
		}
		virtual Coord center_of_gravity() const
		{
			cout<<"Circle:: center_of_gravity() 函数"<<endl;
		}
    //...
};

// concrete geometric object class Line
// - \bfseries not derived from any class
class Line {
  public:
		virtual void draw() const
		{
			cout<<"Line:: draw() 函数"<<endl;
		}
		virtual Coord center_of_gravity() const
		{
			cout<<"Line:: center_of_gravity() 函数"<<endl;
		}
    //...
};
//...
