/*
 * @Author: your name
 * @Date: 2021-06-23 22:59:46
 * @LastEditTime: 2021-06-23 23:04:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/11_Template_argument_deduction/11_05_class_argument_deduction/class_argument_deduction.cpp
 */
#include <iostream>


/*
模板实参演绎只能应用于函数模板和成员函数模板，是不能应用 于类模板的。
另外，对于类模板的构造函数，也不能根据实参来演绎 类模板参数


template<typename T> class S {
public:
S(T b) : a(b) { }
private: T a;
};
S x(12);
  数T
//错误:不能从构造函数的调用实参12演绎类模板参
*/
template<class T=int> 
class S {
public:
    S(T b) : a(b) 
    {

    }
    private: T a;
};

int main()
{
    S<int> s(12);
    S<> x2(12);
    //S x(12);

}