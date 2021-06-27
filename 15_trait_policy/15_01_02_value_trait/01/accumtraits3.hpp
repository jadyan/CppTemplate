/*
 * @Author: your name
 * @Date: 2021-06-25 14:06:11
 * @LastEditTime: 2021-06-25 14:20:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Editmake
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_02_value_trait/01/accumtraits3.hpp
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
template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char> {
  public:
    typedef int AccT;
    static AccT const zero = 0;
};

template<>
class AccumulationTraits<short> {
  public:
    typedef int AccT;
    static AccT const zero = 0;
};

template<>
class AccumulationTraits<int> {
  public:
    typedef long AccT;
    static AccT const zero = 0;
};

template<>
class AccumulationTraits<unsigned int> {
	public:
		   typedef unsigned long AccT;
       static AccT const zero = 0;
};

#if 0
/*
然而，这种解决方案的一个缺点是：在所在类的内部，C++只允许
我们对整型和枚举类型初始化成静态成员变量。显然，对于诸如浮点
型的其他类型（也包括我们自己定义的类），我们就不能使用上面的
解决方案。譬如下面的特化就是错误的：
*/
template<>
class AccumulationTraits<float> {
	public:
		   typedef double AccT;
       //static AccT const zero = 0;
};

/*
但是这个该解决方法却有一个显著的缺点：
这种解决方法对编译器而言是不可知的。也就是说，在处理客户端文
件的时候，编译器通常都不会知道位于其他文件的定义。于是，在上
面这个例子中，编译器根本就不能够知道zero的值为0这个事实。
因此，我们趋向于实现下面的这种value trait，而且并不需要保证
内联成员函数返回的必须是整型值 
*/
double const AccumulationTraits<float>::zero = 0.0;
#endif

