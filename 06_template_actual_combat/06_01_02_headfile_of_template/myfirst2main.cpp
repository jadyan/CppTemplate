/*
 * @Author: your name
 * @Date: 2021-06-16 11:10:52
 * @LastEditTime: 2021-06-16 11:10:53
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/06_template_actual_combat/06_02_headfile_of_template/myfirst2main.cpp
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
#include "myfirst2.hpp"

// using of template


/*
在实际应用中，这是一个很严重的问题，因为它大大增加了编译
复杂程序所耗费的时间。因此我们将在后面几节给出几种可能的解决
方法。然而，现在的程序大多已经不需要在编译和链接上面花上几个
小时，将来就更不用说了（我们以前确实是耗费了很多时间在这上
面，甚至用了几天的时间才从源代码完整地创建出一个程序）。
如果不需要考虑创建期的时间问题，我们建议你尽量使用包含模
型来组织模板代码。我们在后面会考察另外两种组织模板的方式，但
就我们的观点看来，另外两种组织方式的实际缺陷往往比这里所讨论
的创建期开销更加严重。当然，这两种组织方式也有其他一些与软件
开发的应用方面间接相关的优点。
从包含模型得出的另一个（更微妙的）结论是：非内联函数模板
与“内联函数和宏”有一个很重要的区别，那就是非内联函数模板在调
用的位置并不会被扩展，而是当它们基于某种类型进行实例化之后，
才产生一份新的（基于该类型的）函数拷贝。因为这（产生函数拷
贝）是一个自动化过程，所以在编译结束的时候，编译器可能会在不
同的文件里产生两份拷贝，于是，当链接器发现同一个函数具有两种
不同的定义时，就会报告一个错误。理论上讲，这并不是我们需要关
心的问题，它应该由 C++的编译系统来解决。而且，事实上大多数情
况下都不会出现这种问题，我们根本没有必要太过于在意这个问题。
但对于需要创建自身代码库的大项目，我们就要充分注意这个问题。
我们将在第10章详细讨论C++的实例化机制；仔细学习 C++翻译系统
（或者编译器）所附带的随机文档也有助于理解这个问题。
最后，我们需要指出的是：在我们的例子中应用到普通函数模板
的所有特性，对类模板的成员函数和静态数据成员、成员函数模板也
都是适用的。
*/

int main()
{
    double ice = 3.0;
    print_typeof(ice);  // call function template for type double
}
