/*
 * @Author: your name
 * @Date: 2021-06-24 13:27:33
 * @LastEditTime: 2021-06-24 13:27:34
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_02_01_The_signature/The_signature.cpp
 */
#include <iostream>
template<typename T1, typename T2>
void f1(T1, T2)
{
    std::cout << "f1(T1, T2)\n";
}

#if 0
template<typename T1, typename T2>
void f1(T2, T1)
{
    std::cout << "f1(T2, T1)\n";
}
#endif

// 到这里为止一切都是正确的
int main()
{
    f1<char, char>('a', 'b'); // 错误：二义性
}
