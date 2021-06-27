/*
 * @Author: your name
 * @Date: 2021-06-24 13:31:45
 * @LastEditTime: 2021-06-24 13:36:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_02_01_The_signature/Different_unit/The_signature1.cpp
 */
// 翻译单元1:
#include <iostream>
template<typename T1, typename T2>
void f1(T1, T2)
{
	std::cout << " 1: f1(T1, T2)\n";
}
void g()
{
	f1<char, char>('a', 'b');
}