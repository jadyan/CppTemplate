/*
 * @Author: your name
 * @Date: 2021-06-25 09:21:21
 * @LastEditTime: 2021-06-25 09:30:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/13_template_polymorphism/13_01_dynamic_polymorphism/dynahier.hpp
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

#ifndef _GEOBJ_HPP_
#define _GEOBJ_HPP_

#include <iostream>
#include "coord.hpp"
using namespace std;

// common abstract base class GeoObj for geometric objects
class GeoObj {
	public:
		// draw geometric object:
		virtual void draw() const = 0;
		// return center of gravity of geometric object:
		virtual Coord center_of_gravity() const = 0;
		//...
};

// concrete geometric object class Circle
// - derived from GeoObj
class Circle : public GeoObj {
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
// - derived from GeoObj
class Line : public GeoObj {
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


#endif // MYFIRST_HPP
