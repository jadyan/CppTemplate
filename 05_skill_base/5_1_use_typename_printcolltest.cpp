/*
 * @Author: your name
 * @Date: 2021-06-15 13:25:57
 * @LastEditTime: 2021-06-15 13:28:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_1_use_typename_printcolltest.cpp
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
#include <vector>
#include <list>
#include "printcoll.hpp"

int main()
{
    std::vector<int> v;

    v.push_back(42);
    v.push_back(13);
    v.push_back(7);
    printcoll(v);

std::cout<<"------------------------"<<std::endl;
    std::list<int> tmplist;
    tmplist.push_back(27);
    tmplist.push_back(18);
    tmplist.push_back(15);
    tmplist.push_back(19);
    printcoll(tmplist);

}
