/*
 * @Author: your name
 * @Date: 2021-06-22 22:10:29
 * @LastEditTime: 2021-06-22 22:32:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/09_template_name/09_02_01_Argument_Dependent_Lookup/adl.cpp
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

namespace X {
    template<typename T> void f(T);
}

namespace N {
    using namespace X;
    enum E { e1 };
    void f(E) 
    { 
        std::cout << "----N::f(N::E) called\n"; 
    }
}

void f(int) 
{ 
    std::cout << "-----::f(int) called\n"; 
}


/*
当我们给函数传递一个类类型的对象时，首先会在常规的作用域查找，其次在实参类所属的命名空间查找。
查找顺序如下：
1. 先在本作用域内查找；
2. 在实参的命名空间 和 全局作用域中 同时查找；

这一规则也叫做argument-dependent lookup或Koening lookup法则。这一规则对传递类的引用或指针的调用同样有效。
如果名称后面的括号里面有一个或多个实参表达式，那么ADL将会查找这些实参直接相关的所有namespace和class。
其中，类包括直接基类和间接基类。Andrew Koenig首次提出了ADL，这也是为什么ADL有时也称为koenig查找的原因。
最初ADL引入的动机只是为了方便编写a+b，其中a和b至少有一个是用户自定义类型。如果没有ADL，

*/
int main() 
{
    ::f(N::e1);  // qualified function name: no ADL  受限函数名称:不会使用ADL
    f(N::e1);    // ordinary lookup finds ::f() and ADL finds N::f(), 普通查找将找到f(); ADL 将找到 N::f(),
}                //  the latter is preferred  将会调用后者

