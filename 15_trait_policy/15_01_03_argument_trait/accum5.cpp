/*
 * @Author: your name
 * @Date: 2021-06-25 14:54:41
 * @LastEditTime: 2021-06-25 15:19:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_03_argument_trait/accum5.cpp
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
#include "accum5.hpp"
#include "accumtraits4.hpp"
#include <iostream>


/*
在上一节所使用的trait被称为fixed trait，因为一旦定义了这个分离
的trait，就不能在算法中对它进行改写。然而，在有些情况下我们需要
对trait进行改写。例如，我们可能偶然发现可以对一组float值进行求
和，然后很安全地把和值存储在一个具有相同类型（即float型）的变量
里面，而且这样通常能够给我们带来更高的效率。
从原则上讲，参数化trait主要的目的在于：添加一个具有缺省值的
模板参数，而且该缺省值是由我们前面介绍的trait模板决定的。在这种
具有缺省值的情况下，许多用户就可以不需要提供这个额外的模板实
参；但对于有特殊需求的用户，也可以改写这个预设的和类型。对于
这个特殊的解决方案，

唯一的不足在于：我们并不能对函数模板预设缺省模板实参[7]。

就现在的情况而言，通过把算法实现为一个类，我们就可以绕过
上面这个不足。这同时也说明了：除了函数模板之外，在类模板中也
可以很容易地使用trait。在我们的应用程序中，唯一的缺点就是：类模
板不能对它的模板参数进行演绎，而是必须显式提供这些模板参数。
因此，我们需要编写如下形式的代码
*/
int main()
{
    // create array of 5 integer values
    int num[] = { 1, 2, 3, 4, 5 };

    // print average value
#if 1
    std::cout << "the average value of the integer values is "
              << Accum<int>::accum(&num[0], &num[5]) / 5
              //<< Accum<int,AccumulationTraits<int>>::accum(&num[0], &num[5]) / 5
              << '\n';
#else
    /*
    使用辅助函数， 简化调用
    */
    std::cout << "the average value of the integer values is "
              << accum(&num[0], &num[5]) / 5
              << '\n';
#endif

    // create array of character values
    char name[] = "templates";
    int length = sizeof(name)-1;

#if 0
    // (try to) print average character value
    std::cout << "the average value of the characters in \""
              << name << "\" is "
              << Accum<char>::accum(&name[0], &name[length]) / length
              << '\n';
#else
    /*
    使用辅助函数， 简化调用
    */
        // (try to) print average character value
    std::cout << "the average value of the characters in \""
              << name << "\" is "
              << accum<AccumulationTraits<char>, char> (&name[0], &name[length]) / length
              << '\n';
#endif
}
