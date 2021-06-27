/*
 * @Author: your name
 * @Date: 2021-06-23 15:17:41
 * @LastEditTime: 2021-06-23 15:50:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/10_temp_instantiation/10_02_delay_init/lazy.cpp
 */
/* The following code example is taken from the book
 * "C++ Templates - The Complete Guide"
 * by David Vandevoorde and Nicolai M. Josuttis, Addison-Wesley, 2002
 *
 * (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>

/*
模板中没有用到就不会实例化，所以才不会报错

使用非模板类时的一些约束并没有本质的区别。譬如，非模板类的许多用法
会要求class类型的定义是完整的；类似地，编译器同样可以根据类模
板定义，产生这个完整的定义。
现在就有了一个相关的问题：模板的实例化程度是怎么样的呢？
对于这个问题，一个模糊的回答会是：只对确实需要的部分进行实例
化。换句话说，编译器会延迟模板的实例化。让我们细究“延迟”在这
里的具体含义。
当隐式实例化类模板时，同时也实例化了该模板的每个成员声明，但并没有实例化相应的定义。

然而，存在一些例外的情况：首先，如果类模板包含了一个匿名的 【union】，那么该union 定义的成员同时也被实例化了[31]。
                        另一种例外情况发生在【虚函数】身上：作为实例化类模板的结果，虚函数的定义可能被实例化了，但也可能还没有被实例化，这要依赖于具体的实现。
						实际上，许多实现都会实例化（虚函数）这个定义，因为“实现虚函数调用机制的内部结构”要求虚函数（的定义）作为链接实体存在。
当实例化模板的时候，缺省的函数调用实参是分开考虑的。

准确而言，只有这个被调用的函数（或成员函数）确实使用了缺省实参，才会实例化该实参。就是说，
如果这个函数（或成员函数）不使用缺省调用实参，而是使用显式实参来进行调用，那么就不会实例化缺省
实参。

*/

template <typename T> 
class Safe {
};

template <int N>
class Danger {
	public:
		typedef char Block[N];  // would fail for N<=0 如果N<=0的话 将会出错
};

template <typename T, int N>
class Tricky {
	public:
		virtual ~Tricky()
		{
		}
		void no_body_here(Safe<T> = 3);
		/*
			对于成员inclass()和结构（struct）Nested的定义，它
			们会要求一个完整的 Danger<0>类型（而我们从前面讨论已经知道，该
			完整类型会包含一个无效的 typedef）；但因为程序中并不会用到这两
			个成员的定义，因此不会产生它们的定义，从而也就不会引发错误
		*/
		void inclass() 
		{ 
			Danger<N> no_boom_yet;
		}
		//void error() { Danger<0> boom;}
		//void unsafe(T (*p)[N]);

		/*
		我们需要考察operator->。通常，这个运算符必须返回一个
		指针类型，或者另一个应用这个operator->的class类型。这就意味着
		main函数中的Ticky<int, 0>应该会引发一个错误，因为它声明了一个返
		回类型为int的operator->。然而，因为某些常见的类模板定义[34]实现
		了这种（返回类型为T或者T*的）定义，所以语言规则就变得更加灵活
		了；于是，如果通过重载解析规则选择了用户定义的operator->，那么
		这个自定义的operator->只能返回一个类型，而且此类型是应用其他
		（例如内建的）operator->的类型。这在模板之外的代码也是适用的
		（即使在那些情况下用处不多）。因此，即使用int来作为返回类型，
		这个operator->声明也不会引发错误
		*/
		T operator->();

		/*
			没有注释掉虚
			函数成员 suspect()的声明，也没有提供它的定义的话，链接器就会给出
			这类错误。
		*/
		//virtual Safe<T> suspect();
		struct Nested { 
			Danger<N> pfew; 
		};
		union {  // anonymous union
			int align;
			Safe<T> anonymous;
			//Danger<N>  anonymous;
		};
};

int main()
{
	Tricky<int, 0> ok;
}
