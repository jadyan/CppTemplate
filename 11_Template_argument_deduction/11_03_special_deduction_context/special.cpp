/*
 * @Author: your name
 * @Date: 2021-06-23 22:18:41
 * @LastEditTime: 2021-06-23 22:43:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/11_Template_argument_deduction/11_03_special_deduction_context/special.cpp
 */

#include <iostream>


/*
第1种情况出现在取函 数模板地址的时候。在这种情况下，
P是函数模板声明子的参数化类型 (即下面的 f 的类型)，
而 A 是被赋值(或者初始化)的指针(即下 面的pf)所代表的函数类型。
*/
using namespace std;

template<typename T>
void f(T t1, T t2) 
{
    cout<<"t1 = "<<t1<<" t2 ="<<t2<<endl;
}

#if 0
class S 
{ 
public:
    template<typename T, int N> 
    operator T[N]&()
    {
        //return T;
    }
 };

 void f(int (&)[20])
 {

 }
void g(S s) 
{
    f(s); 
}
#endif

int main(int argc, char** argv)
{
    void (*pf)(char,char) = &f;
    pf('c','b');

    void (*pf2)(string, string) =&f;
    pf2("jadyan", "jeffry");
}