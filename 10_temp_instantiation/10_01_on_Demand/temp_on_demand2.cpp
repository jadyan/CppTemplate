/*
 * @Author: your name
 * @Date: 2021-06-23 14:46:15
 * @LastEditTime: 2021-06-23 15:11:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/10_temp_instantiation/10_01_on_Demand/temp_on_demand.cpp
 */
#include <iostream>

using namespace std;


template<typename T>
class C 
{
	public:
	C(int); //具有单参数的构造函数
	//可以被用于隐式类型转换
};
void candidate(C<double> const&); //(1)
void candidate(int) 
{
	cout<<"candidate(int)  函数"<<endl;
} //(2)


/*
调用 candidate(42)将会采用（2）处的重载声明。然而，编译器仍
然可以实例化（1）处的声明，来检查产生的实例能否成为该调用的一
个有效候选函数（之所以这样，是因为在这个例子中，单参数的构造
函数可以将42隐式转型为一个C<double>类型的右值）。我们应该看
到：即使不进行这种实例化，编译器也可以解析这个调用，即调用
（2）处的声明；但是编译器并不会拒绝这种实例化，它是允许（但并
没有要求）执行这种实例化的（这也正如该例子所示：它并不需要
（也不会选择）（1）处的声明，
因为一个精确的匹配要优于显式转型所获得的匹配）。

另外，令我们惊讶的是：C<double>的实例化可能还
会引发一个错误。
*/

int main()
{
	candidate(42); //前面两个函数声明都可以被调用

	//C<double> dc(42);
}