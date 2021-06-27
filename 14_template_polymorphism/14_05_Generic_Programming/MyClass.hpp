/*
 * @Author: your name
 * @Date: 2021-06-25 10:33:18
 * @LastEditTime: 2021-06-25 10:51:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/13_template_polymorphism/13_05_Generic_Programming/MyClass.hpp
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

 using namespace std;
class MyClass {
  private:
    int value;
  public:
    MyClass(int i=0):value(i){}
#if 1
    /*
    必须要重载该< 不然max_element 无法进行比对
    */
    friend bool operator < (MyClass const& x, MyClass const& y) {
        cout<<"operator < 函数"<<endl;
        return x.value < y.value;
    }
#endif
    friend std::ostream& operator << (std::ostream& strm, MyClass const& x) {
         cout<<"operator << 输出函数"<<endl;
        strm << x.value;
        return strm;
    }
};

