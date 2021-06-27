/*
 * @Author: your name
 * @Date: 2021-06-15 13:57:29
 * @LastEditTime: 2021-06-15 14:20:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_2_use_this.cpp
 */
#include <iostream>

using namespace std;

/*

在foo()内部决定要调用哪一个exit()时，并不会考
虑基类Base中定义的exit()。因此，你如果不是获得一个错误，就是调
用了另一个exit()。
我们将在9.4.2小节详细讨论这个问题。现在建议你记住一条规
则：对于那些在基类中声明，并且依赖于模板参数的符号（函数或者
变量等），你应该在它们前面使用 this->或者Base<T>::。如果希望完全
避免不确定性，你可以（使用诸如this->和Base<T>::等）限定（模板
中）所有的成员访问。

/home/jadyan/code/book/effectivecpp/Chap07_Templates_Generics/43Item_02.cpp

*/

template <typename T>
class Base {
    public:
    void myexit()
    {
        cout<<"Base::myexit"<<endl;
    }

    void myexit2()
    {
        cout<<"Base::myexit2"<<endl;
    }

    void myexit3()
    {
        cout<<"Base::myexit3"<<endl;
    }
};

template <typename T>
class Derived : public Base<T> {
    public:
    void foo() 
    {
    //第一种 使用this
        this->myexit(); //调用外部的exit()或者出现错误
    }

    void foo2()
    {
    //第二种 明白指出被调用函数位于 base class 内
        Base<T>::myexit2();
    }

    //第三种是使用 using 声明式；
    using Base<T>::myexit3;
    void foo3()
    {
        myexit3();
    }
};



int main(int argc, char ** argv)
{
    Derived<int> d;
    d.foo();
    d.foo2();
    d.foo3();
}