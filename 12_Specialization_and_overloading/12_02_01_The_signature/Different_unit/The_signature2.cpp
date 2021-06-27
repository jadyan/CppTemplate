/*
 * @Author: your name
 * @Date: 2021-06-24 13:31:54
 * @LastEditTime: 2021-06-24 13:39:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_02_01_The_signature/Different_unit/The_signature2.cpp
 */
// 翻译单元2:
#include <iostream>
template<typename T1, typename T2>
void f1(T2, T1)
{
	std::cout << "2: f1(T2, T1)\n";
}
extern void g(); // 定义在翻译单元 1
/*
说明模板只是对自己文件有效
*/
int main()
{
	f1<char, char>('a', 'b');
	g();
}