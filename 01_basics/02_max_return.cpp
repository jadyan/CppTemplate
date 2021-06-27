/*
 * @Author: your name
 * @Date: 2021-06-02 23:42:56
 * @LastEditTime: 2021-06-03 09:53:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/01_basics/02_max_return.cpp
 */
#include <iostream>
using namespace std;

template <typename T>
inline T const& max (T const& a, T const& b)
{
	cout<<"两参函数模板！"<<endl;
	return  a < b ? b : a;
}

template <typename T1, typename T2, typename RT>
inline RT max2 (T1 const& a, T2 const& b)
{
	cout<<"指定返回值类型！"<<endl;
	return  a < b ? b : a;
}



/*
相对于02来讲
。另一种情况是只显式指
定第一个实参，而让演绎过程推导出其余的实参。通常而言，你必须
指定“最后一个不能被隐式演绎的模板实参之前的”所有实参类型。因
此，在上面的例子里，
如果你改变模板参数的声明顺序，那么调用者
就只需要指定返回类型

先声明返回值类型，只指定返回值类型
*/

template <typename RT, typename T1, typename T2>
inline RT max3 (T1 const& a, T2 const& b)
{
	cout<<"只指定返回值类型！"<<endl;
	return  a < b ? b : a;
}

int main()
{
	//cout<<"两参数："<<::max(5,4.2 )<<endl;
	//用double来实例化T
	cout<<"两参数："<<::max<double>(5,4.2 )<<endl;
	
	//显式地指定模板实参列表 //OK, 但是很麻烦	
	cout<<"指定返回值"<<::max2<int, double, double>(6,4.2)<<endl;
	//cout<<"指定返回值"<<::max2<double>(4,4.2)<<endl;
	//::max2<double>(4,4.2);


	cout<<"只指定返回值类型"<<::max3<double>(4, 4.2)<<endl;
}
