/*
 * @Author: your name
 * @Date: 2021-06-16 20:52:13
 * @LastEditTime: 2021-06-16 20:52:14
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/06_template_actual_combat/06_02_explicit_instantiation/06_02_02_inis/explicitTemplateInstantiation/stack1.hpp
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
#include <stdexcept>

template <typename T>
class Stack {
  private:
    std::vector<T> elems;     // elements

  public:
    Stack(){}
    void push(T const&);      // push element
    void pop();               // pop element
    T top() const;            // return top element
    bool empty() const {      // return whether the stack is empty
        return elems.empty();
    }
};
