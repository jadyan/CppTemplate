/*
 * @Author: your name
 * @Date: 2021-06-09 21:21:15
 * @LastEditTime: 2021-06-09 21:29:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/03_classtemplate/stack2.hpp
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
#include <deque>
#include <string>
#include <stdexcept>
#include "stack1.hpp"

using namespace std;
/*类模板特化
使用了一个deque，而不是vector，来管理
stack内部的元素。我们使用这种用法并不在于获得某种好处[13]，而只
是为了说明：特化的实现可以和基本类模板（prinmary template）的实
现完全不同

*/
template<>
class Stack<std::string> {
  private:
    std::deque<std::string> elems;  // elements

  public:
    void push(std::string const&);  // push element
    void pop();                     // pop element
    std::string top() const;        // return top element
    bool empty() const {            // return whether the stack is empty
        return elems.empty();
    }
};

void Stack<std::string>::push (std::string const& elem)
{
    cout<<"Stack 特化 push"<<endl;
    elems.push_back(elem);    // append copy of passed elem
}

void Stack<std::string>::pop ()
{
    cout<<"Stack 特化 pop"<<endl;
    if (elems.empty()) {
        throw std::out_of_range
                ("Stack<std::string>::pop(): empty stack");
    }
    elems.pop_back();         // remove last element
}

std::string Stack<std::string>::top () const
{
     cout<<"Stack 特化 top"<<endl;
    if (elems.empty()) {
        throw std::out_of_range
                ("Stack<std::string>::top(): empty stack");
    }
    return elems.back();      // return copy of last element
}
