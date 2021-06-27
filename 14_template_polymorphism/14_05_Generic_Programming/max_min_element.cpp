/*
 * @Author: your name
 * @Date: 2021-06-25 10:43:44
 * @LastEditTime: 2021-06-25 10:45:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/13_template_polymorphism/13_05_Generic_Programming/max_min_element.cpp
 */
//本程序示范min_element和max_element的正确用法
//既实现了无条件的最小值最大值求取，还实现了利用仿函数的最大值最小值的求取
//本程序中仿函数的作用是利用元素绝对值进行比较
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
template<class T>
void FillValue(T& vect,int first,int last){
    if(last>=first){
        for(int i=first;i<=last;++i){
            vect.insert(vect.end(),i);   //在最后添加一个值为i的元素
        }
    }
}
 
//用于在for_each中输出容器中的元素
void print(const int elem){
    cout<<elem<<",";
}
 
//用于min_element和max_element中的第三个参数
bool AbsLess(int elem1,int elem2){
    return abs(elem1)<abs(elem2);
}
 
int main()
{
    vector<int> myvec;
    FillValue(myvec,-3,12);
    for_each(myvec.begin(),myvec.end(),print);
    cout<<endl;
    cout<<"min_element: "<<*min_element(myvec.begin(),myvec.end())<<endl;
    cout<<"max_element: "<<*max_element(myvec.begin(),myvec.end())<<endl;
    cout<<"abs:min_element: "<<*min_element(myvec.begin(),myvec.end(),AbsLess)<<endl;
    cout<<"abs:max_element: "<<*max_element(myvec.begin(),myvec.end(),AbsLess)<<endl;
    return 0;
}
