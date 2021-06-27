/*
 * @Author: your name
 * @Date: 2021-06-23 21:48:58
 * @LastEditTime: 2021-06-23 22:03:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/11_Template_argument_deduction/11_02_deduction_context/my_fppm.cpp
 */
#include <iostream>

using namespace std;


template<typename T>
void f1(T*)
{
    cout<<"f1(T*)调用"<<endl;
}

template<typename E, int N>
void f2(E(&)[N])
{
    cout<<"2(E(&)[N]) 调用 N = "<<N<<endl;
}

template<typename T1, typename T2, typename T3>
void f3(T1 (T2::*)(T3*) )
{
    cout<<"f3(T1 (T2::*)(T3*) )调用"<<endl;
    cout<<"演绎成T1=void， T2=是， T3=double"<<endl;
}

class S 
{ 
public:
    void f(double*);
};

void S::f( double *)
{

}

void g(int*** ppp) 
{
    bool b[42];

cout<<"f1(ppp):"<<endl;
    f1(ppp);   //演绎成int**
cout<<"f2(b):"<<endl;
    f2(b);     //演绎为E为bool， N 为42
cout<<"f3(&S::f):"<<endl;
    f3(&S::f);  //演绎成T1=void， T2=是， T3=double
}


int main(int argc, char ** argv)
{
    int i;

    g((int ***)&i);
    return 0;
}