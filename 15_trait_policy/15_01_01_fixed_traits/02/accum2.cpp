/*
 * @Author: your name
 * @Date: 2021-06-25 13:54:31
 * @LastEditTime: 2021-06-25 13:54:32
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_01_fixed_traits/02/accum2.cpp
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
#include "accum2.hpp"
#include <iostream>


/*
现在例子程序的输出完全符合我们的期望，具体如下：
the average value of the integer values is 3
the average value of the characters in "templates" is 108
总体而言，上面的修改增加了一个非常有用的机制，从而可以自
定义我们的算法，从这个意义上考虑它还是比较灵活方便的。进一步
而言， 如果有新的类型要使用 accum() 模板， 那么只需声明
AccumulationTraits模板的一个新的显式特化来关联Acct和该类型即可。
我们还看到，任何类型都可以和Acct进行关联，来实现这种trait；这些
类型包括基本类型、在其他程序库中声明的类型等。

*/
int main()
{
    // create array of 5 integer values
    int num[] = { 1, 2, 3, 4, 5 };

    // print average value
    std::cout << "the average value of the integer values is "
              << accum(&num[0], &num[5]) / 5
              << '\n';

    // create array of character values
    char name[] = "templates";
    int length = sizeof(name)-1;

    // (try to) print average character value
    std::cout << "the average value of the characters in \""
              << name << "\" is "
              << accum(&name[0], &name[length]) / length
              << '\n';
}
