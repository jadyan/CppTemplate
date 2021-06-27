/*
 * @Author: your name
 * @Date: 2021-06-23 22:53:36
 * @LastEditTime: 2021-06-23 22:54:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edi
 * @FilePath: /jadyan/code/book/CppTemplate/read/11_Template_argument_deduction/11_04_Acceptable_argument_deduction/Acceptable.cpp
 */

#include <iostream>


/*

11.4 可接受的实参转型
通常，模板演绎过程会试图找到函数模板参数的一个匹配，以使 参数化类型P等同于类型A。然而，当找不到这种匹配的时候，下面的 几种变化就是可接受的:
•如果原来声明的参数是一个引用参数子，那么被替换的P类型可 以比A类型多一个const或者volatile限定符。
•如果 A 类型是指针类型或者成员指针类型，那么它可以进行限定 符转型(就是说，添加const或者volatile限定符)，转化为被替换的P类 型。

•当演绎过程不涉及到转型运算符模板的时候，被替换的P类型可 以是A类型的基类;或者当A是指针类型时，
    P可以是一个指针类型， 它所指向的类型是A所指向的类型的基类。见下面的例子:
*/
using namespace std;

template<typename T>
class B 
{
};

template<typename T> 
class D : public B<T> 
{

};

template<typename T> 
void f(B<T>*)
{
    cout<<"f(B<T>*) 调用"<<endl;
}

void g(D<long> dl)
{
    f(&dl); //成功演绎:用long替换T 
}

int main()
{
   D<long> dl;
   g(dl) ;
}