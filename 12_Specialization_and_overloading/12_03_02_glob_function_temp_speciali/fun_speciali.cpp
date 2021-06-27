/*
 * @Author: your name
 * @Date: 2021-06-24 14:44:54
 * @LastEditTime: 2021-06-24 14:45:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_03_02_glob_function_temp_speciali/fun_speciali.cpp
 */
//12.3.2 全局的函数模板特化

#include <iostream>

using namespace std;

template<typename T>
int f(T, T x = 42)
{
	return x;
}
//template<> int f(int, int = 35) // 错误，不能包含缺省实参值
template<> int f(int, int) // 错误，不能包含缺省实参值
{
	return 0;
}
template<typename T>
int g(T, T x = 42)
{
	return x;
}
template<> int g(int, int y)
{
	return y/2;
}
int main()
{
	std::cout << g(0) << std::endl; // 正确，输出21
}