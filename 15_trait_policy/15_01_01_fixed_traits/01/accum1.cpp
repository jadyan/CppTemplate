/*
 * @Author: your name
 * @Date: 2021-06-25 13:20:42
 * @LastEditTime: 2021-06-25 13:29:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_01_fixed_traits/accum1.cpp
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
#include "accum1.hpp"
#include <iostream>

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

/*
这里的问题是我们的模板是基于char类型进行实例化的，而char的
范围是很小的，即使对于相对较小的数值进行求和也可能会出现越界
的情况。显然，我们可以通过引入一个额外的模板参数AccT来解决这
个问题，其中AccT描述了变量total的类型（同时也是返回类型）。然
而，这将会给该模板的所有用户都强加一个额外的负担：他们每次调
用这个模板的时候，都要指定这个额外的类型。因此，针对我们上面
的例子，我们不得不这样编写代码：
accum<int>(&name[0],&name[length]) (有点问题)
*/
    // (try to) print average character value
#if 1
    std::cout << "the average value of the characters in \""
              << name << "\" is "
              << accum(&name[0], &name[length]) / length
              << '\n';
#else
    std::cout << "the average value of the characters in \""
              << name << "\" is "
              << accum<int>(&name[0], &name[length]) / length
              << '\n';
#endif
}
