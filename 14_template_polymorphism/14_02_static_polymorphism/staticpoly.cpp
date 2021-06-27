/*
 * @Author: your name
 * @Date: 2021-06-25 09:51:58
 * @LastEditTime: 2021-06-25 10:01:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/13_template_polymorphism/13_02_static_polymorphism/staticpoly.cpp
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
#include "statichier.hpp"
#include <vector>

// draw any GeoObj
template <typename GeoObj>
void myDraw (GeoObj const& obj)
{
    obj.draw();    // call draw() according to type of object
}

// process distance of center of gravity between two GeoObjs
template <typename GeoObj1, typename GeoObj2>
Coord distance (GeoObj1 const& x1, GeoObj2 const& x2)
{
    Coord c = x1.center_of_gravity() - x2.center_of_gravity();
    return c.abs();  // return coordinates as absolute values
}

// draw homogeneous collection of GeoObjs
template <typename GeoObj>
void drawElems (std::vector<GeoObj> const& elems)
{
    for (unsigned i=0; i<elems.size(); ++i) {
        elems[i].draw();    // call draw() according to type of element
    }
}


/*
14.2 静多态
模板也能够被用于实现多态。然而，这种多态并不依赖于在基类
中包含公共行为的因素；但仍然存在一种隐式的公共性，即应用程序
的不同“形状（即类型）”都必须支持某些使用公共语法的操作（也就
是说，相关的函数必须具有相同的名称）。另外，具体类之间的定义
是互相独立的（见图14.2）。于是，当用具体类对模板进行实例化的时
候，这种多态的威力就显示出来了。

静态的含义是：接口的绑定是在编译期（静态）完成的。
*/

int main()
{
    Line l;
    Circle c, c1, c2;

    myDraw(l);        // myDraw<Line>(GeoObj&) => Line::draw()
    myDraw(c);        // myDraw<Circle>(GeoObj&) => Circle::draw()

    distance(c1,c2);  // distance<Circle,Circle>(GeoObj1&,GeoObj2&)
    distance(l,c);    // distance<Line,Circle>(GeoObj1&,GeoObj2&)

    // std::vector<GeoObj*> coll;    // ERROR: no heterogeneous
                                   //      collection possible
    std::vector<Line> coll;   // OK: homogeneous collection possible
    coll.push_back(l);        // insert line
    drawElems(coll);          // draw all lines
}
