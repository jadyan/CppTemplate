/*
 * @Author: your name
 * @Date: 2021-06-15 17:27:50
 * @LastEditTime: 2021-06-15 17:39:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/05_skill_base/5_5_template_init.cpp
 */
#include <iostream>
#include <string>
using namespace std;


template <typename T>
void foo(T t)
{

    //T x;       //如果T是内建类型，那么x本身是一个不确定值
    T x = T(); //如果T是内建类型，x是零或者false
    cout<<"x = "<<x<<endl;
    cout<<"x+t = "<<x+t<<endl;
}


/*
对于类模板，在用某种类型实例化该模板后，为了确认它所有的
成员都已经初始化完毕，需要定义一个缺省构造函数，通过一个初
始化列表来初始化类模板的成员
*/
template <typename T>
class MyClass {
private:
    T x;
public:
#if 0
    MyClass() {}
#else
    MyClass() : x() 
    {
        //确认x已被初始化，内建类型对象也是
    }
#endif
    void show()
    {
        cout<<"MyClass::x = "<< x <<endl;
    }
};



int main(int argc, char ** argv)
{
    int  a=3;
    foo(a);

    MyClass<int> my;
    my.show();
}