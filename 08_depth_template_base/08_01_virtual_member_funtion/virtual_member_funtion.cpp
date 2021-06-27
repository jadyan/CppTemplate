/*
 * @Author: your name
 * @Date: 2021-06-21 21:53:08
 * @LastEditTime: 2021-06-21 22:12:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/08_depth_template_base/08_01_virtual_member_funtion/virtual_member_funtion.cpp
 */
#include <iostream>
#include <string>

using namespace std;

template <typename T> 
class Dynamic 
{
private:
    T m_a;
public:
    Dynamic():m_a(){}
    virtual ~Dynamic (){} //OK:每个Dynamic只对应一个析构函数 

    //错误:在确定Dynamic<T>实例的 //时候，并不知道copy()的个数
#if 0
//成员函数模板不能被声明为虚函数。这是一种需要强制执行的限 制，因为虚函数调用机制的普遍实现都使用了一个大小固定的表，
//每 个虚函数都对应表的一个入口。然而，成员函数模板的实例化个数， 要等到整个程序都翻译完毕才能够确定，
//这就和表的大小(是固定 的)发生了冲突。因此，如果(将来)要支持虚成员函数模板，将需 要一种全新的C++编译器和链接器的机制。
//相反，类模板的普通[6]成员可以是虚函数，因为当类被实例化之 后，它们的个数是固定的:
    template <typename T2>
    void copy (T2 const& tmp)
    {
        this->m_a=tmp;
        cout<<"copy 函数 m_a"<<this->m_a<<endl;
    }; 
#else
    template <typename T2>
    void copy (T2 const& tmp)
    {
        this->m_a=tmp;
        cout<<"copy 函数 m_a = "<<this->m_a<<endl;
    }; 
#endif
    
    virtual void show()
    {
        cout<<"Dynamic::show()函数 m_a = "<<this->m_a<<endl;
    }
    virtual void set( const T & x)
    {
        this->m_a=x;
    }
};

template<typename T>
class Dvive:public Dynamic<T>{

public:
    

};



int main( int argc, char ** argv)
{
    Dynamic<int> d;
    d.set(27);
    d.show();
    d.copy(3);

    return 0;
}