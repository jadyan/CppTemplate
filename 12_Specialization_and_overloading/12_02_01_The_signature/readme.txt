只要具有不同的签名，两个函数就可以在同一个程序中同时存
在。我们对函数的签名定如下[58]：
1.非受限函数的名称（或者产生自函数模板的这类名称）。
2.函数名称所属的类作用域或者名字空间作用域；如果函数名称是
具有内部链接的，还包括该名称声明所在的翻译单元。
3.函数的const、volatile或者const volatile限定符（前提是它是一个
具有这类限定符的成员函数）。
4.函数参数的类型（如果这个函数是产生自函数模板的，那么指的
是模板参数被替换之前的类型）。
	
5.如果这个函数是产生自函数模板，那么包括它的返回类型。
6.如果这个函数是产生自函数模板，那么包括模板参数和模板实
参。
这就意味着：从原则上讲，下面的模板和它们的实例化体可以在
同个程序中同时存在：
	
template<typename T1, typename T2>
void f1(T1, T2);
template<typename T1, typename T2>
void f1(T2, T1);
template<typename T>
long f2(T);
template<typename T>
char f2(T);
然而，如果上面这些模板是在同一个作用域中进行声明的话，我
们可能不能使用某些模板，因为实例化过程可能会导致重载二义性。
例如：
	
#include <iostream>
template<typename T1, typename T2>
void f1(T1, T2)
{
std::cout << "f1(T1, T2)\n";
}
template<typename T1, typename T2>
void f1(T2, T1)
{
std::cout << "f1(T2, T1)\n";
}
// 到这里为止一切都是正确的
int main()
{
f1<char, char>('a', 'b'); // 错误：二义性
}
在上面的代码中，虽然函数f1<T1 = char, T2 = char>(T1,T2)可以和
函数f1<T1 = char, T2 =char>(T2, T1)同时存在，但是重载解析规则将不
知道应该选择哪一个函数。因此，只有在这两个模板出现于不同的翻
译单元时，它们的两个实例化体才可以在同个程序中同时存在（而
且，链接器也不应该抱怨说存在重复定义，因为这两个实例化体的签
名是不同的）：
// 翻译单元1:
#include <iostream>
template<typename T1, typename T2>
void f1(T1, T2)
{
	std::cout << "f1(T1, T2)\n";
}
void g()
{
	f1<char, char>('a', 'b');
}
// 翻译单元2:
#include <iostream>
template<typename T1, typename T2>
void f1(T2, T1)
{
	std::cout << "f1(T2, T1)\n";
}
extern void g(); // 定义在翻译单元 1
int main()
{
	f1<char, char>('a', 'b');
	g();
}
这个程序是有效的，而且产生的输出如下：
f1(T2, T1)
f1(T1, T2)