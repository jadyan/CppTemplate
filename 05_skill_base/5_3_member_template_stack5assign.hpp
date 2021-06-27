/*
 * @Author: your name
 * @Date: 2021-06-15 14:59:54
 * @LastEditTime: 2021-06-15 15:21:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_3_member_template_stack5assign.hpp
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
template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator= (Stack<T2> const& op2)
{
    if ((void*)this == (void*)&op2) {    // assignment to itself?
        return *this;
    }

    Stack<T2> tmp(op2);              // create a copy of the assigned stack

    elems.clear();                   // remove existing elements
    while (!tmp.empty()) {           // copy all elements
        elems.push_front(tmp.top());  //容器开头增加新的元素
        tmp.pop();
    }
    return *this;
}
