/*
 * @Author: your name
 * @Date: 2021-06-25 09:08:03
 * @LastEditTime: 2021-06-25 10:00:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/13_template_polymorphism/13_01_dynamic_polymorphism/dynapoly.cpp
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
#include "dynahier.hpp"
//#include "coord.hpp"
#include <vector>

/*
14.1 动多态


动态的含义是：接口的绑定是在运行期（动态）完成的。
•通过模板实现的多态是非绑定的和静态的：
非绑定的含义是：对于参与多态行为的类型，它们的接口是没有
预先确定的（有时也称这个概念为非入侵的或者非插入的）。

*/

// draw any GeoObj
void myDraw (GeoObj const& obj)
{
    obj.draw();            // call draw() according to type of object
}

// process distance of center of gravity between two GeoObjs
Coord distance (GeoObj const& x1, GeoObj const& x2)
{
    Coord c = x1.center_of_gravity() - x2.center_of_gravity();
    return c.abs();        // return coordinates as absolute values
}

// draw heterogeneous collection of GeoObjs
void drawElems (std::vector<GeoObj*> const& elems)
{
    for (unsigned i=0; i<elems.size(); ++i) {
        elems[i]->draw();  // call draw() according to type of element
    }
}

int main()
{
    Line l;
    Circle c, c1, c2;

    myDraw(l);            // myDraw(GeoObj&) => Line::draw()
    myDraw(c);            // myDraw(GeoObj&) => Circle::draw()

    distance(c1,c2);      // distance(GeoObj&,GeoObj&)
    distance(l,c);        // distance(GeoObj&,GeoObj&)

    std::vector<GeoObj*> coll;  // heterogeneous collection
    coll.push_back(&l);         // insert line
    coll.push_back(&c);         // insert circle
    drawElems(coll);            // draw different kinds of GeoObjs
}
