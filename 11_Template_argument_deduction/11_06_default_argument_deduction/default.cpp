/*
 * @Author: your name
 * @Date: 2021-06-23 23:10:21
 * @LastEditTime: 2021-06-23 23:20:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/11_Template_argument_deduction/11_06_default_argument_deduction/default.cpp
 */
#include <iostream>


/*
对于缺省调用实参而言，即使不是依赖型的，也不能用于演绎模 板实参。这意味着下面的C++程序是无效的:
template<typename T> 
void f(T x = 42)
{
}
int main()
{
    f<int>(); //正确:T = int
    f(); //错误:不能根据缺省调用实参42来演绎T
}


*/
using namespace std;
template<typename T>
void init(T* loc, T const& val = T() ) 
{
    cout<<"init(T* loc, T const& val = T() ) "<<endl;
    *loc = val; 
}

class S 
{ 
public:
    S(int, int)
    {
        cout<<"有参构造函数"<<endl;
    }
    S()
    {
        cout<<"无参构造函数"<<endl;
    }
};


int main() 
{
    S s(0,0); 
    //因为T=S，所以T()就是无效的了。于是 //缺省调用实参T()也就不需要进行实例化
    //因为已经提供了一个显式参数
    init(&s, S(7,42) ); 
cout<<"xxxxxxxx"<<endl;
    S *p;
    init(p);  //使用默认构造

}