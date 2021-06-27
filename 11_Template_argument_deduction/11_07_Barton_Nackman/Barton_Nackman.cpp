/*
 * @Author: your name
 * @Date: 2021-06-23 23:36:34
 * @LastEditTime: 2021-06-23 23:37:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/11_Template_argument_deduction/11_07_Barton_Nackman/Barton_Nackman.cpp
 */
#include <iostream>

class S {
};
template<typename T> 
class Wrapper {
private:
    T object;
public:
    Wrapper(T obj) : object(obj) 
    {
    //转型为Wrapper<T>
    }
    friend void f(Wrapper<T> const& a) 
    { 

    }
};

/*
调用 f(w)是有效的，因为函数 f()是一个在 Wrapper<S>内部进行声明的友元函数，
而 Wrapper<S>和实参 w 是相关 的[55]。然而，在调用 f(s)中，友元函数的声明f(Wrapper<S> const&)就 不是可见的，
因为类Wrapper<S>和实参s的类型S是不相关联的。因 此，尽管存在一个从S到Wapper<S>的有效隐式转型(借助于 Wrapper<S>的构造函数)，
但此时并不会考虑这种转型，因为编译器 并不能首先找到候选函数 f，当然也就不会考虑 f的参数所要进行的转 型了。

*/

int main()
{
    S s;
    Wrapper<S> w(s);
    //正确:Wrapper<S>是一个和w相关联的类。
    f(w);
    //错误:Wrapper<S>和s不相关联。
    //f(s);
}