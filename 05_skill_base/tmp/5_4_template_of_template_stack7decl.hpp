/*
 * @Author: your name
 * @Date: 2021-06-15 16:26:28
 * @LastEditTime: 2021-06-15 16:52:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_4_template_of_template_stack7decl.hpp
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

template <typename T,
          template <typename ELEM> class CONT = std::deque >

//template <typename T,
//          template <typename ELEM, 
//                    typename = std::allocator<ELEM> >
//                    class CONT = std::deque>

class Stack {
  private:
    CONT<T> elems;         // elements

  public:
    void push(T const&);   // push element
    void pop();            // pop element
    T top() const;         // return top element
    bool empty() const {   // return whether the stack is empty
        return elems.empty();
    }
};
