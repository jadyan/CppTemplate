/*
 * @Author: your name
 * @Date: 2021-06-23 14:46:15
 * @LastEditTime: 2021-06-23 15:05:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/10_temp_instantiation/10_01_on_Demand/temp_on_demand.cpp
 */
#include <iostream>

using namespace std;

/*
只有模板声明是可见的，也就是说：模板定
义此时还不是可见的（这类声明有时也被称为前置声明）

。与普通类
的情况一样，如果你声明的是一个指向某种类型的指针或者引用（如
（2）处的声明），那么在声明的作用域中，你并不需要看到该类模板
的定义。例如，声明函数g的参数类型并不需要模板C的完整定义。然
而，如果（某个组件）期望知道模板特化的大小，或者访问该特化的
成员，那么整个类模板的定义就需要位于作用域中；这也是源代码的

（6）处需要模板定义的原因。因为如果看不见这个模板定义的话，编
译器就不能确定成员f存在且是可访问的（就是说，不是私有的，也不
是受保护的）。

只要不需要知道模板的大小 就只需要声明就好
C<void>* p = new C<void>;
在这个例子中，实例化是必不可少的，因为只有进行实例化之
后，编译器才能知道C<void>的大小。对于上面这个特殊的模板，你可
能会认为：用任何类型的实参 X 替换参数T之后，都不会影响模板（特
化）的大小；因为在任何情况下，C<X>都是一个空类。然而，编译器
并不会检测它是否为空。而且，为了确定 C<void>是否具有可访问的缺
省构造函数， 并且确认C<void> 没有声明私有的operator new 或者
operator delete，我们需要进行实例化。
*/

template<typename T> class C;  //(1)这里只有声明
#if 1
C<int> *p = 0;   //(2)正确:并不需要C<int>的定义  ----指针或者引用 只需要知道声明就好
#else
C<int> p;
#endif


template<typename T>
class C {
	public:
	void f(); //（3）成员声明
}; 			//（4）类模板定义结束

#if 1
template<typename T>
void C<T>::f()
{
	cout<<"c::f()函数"<<endl;
}
#endif




void g (C<int>& c) //（5）只使用类模板声明  ----指针或者引用 只需要知道声明就好
{
	c.f(); //（6）使用了类模板的定义   -----必须要有模板的定义
} // 需要C::f()的定义





int main(int argc, char ** argv)
{
	C<int> c;
	g(c);
	return 0;
}
