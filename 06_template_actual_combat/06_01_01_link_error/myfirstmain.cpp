/*
 * @Author: your name
 * @Date: 2021-06-16 10:56:22
 * @LastEditTime: 2021-06-16 10:56:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/06_template_actual_combat/myfirstmain.cpp
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
#include "myfirstex.hpp"



/*
：函数模板 print_typeof()的定义还没
有被实例化。为了使模板真正得到实例化，编译器必须知道：应该实
例化哪个定义以及要基于哪个模板实参来进行实例化。遗憾的是，在
前面的例子里，这两部分信息位于分开编译的不同文件里面。因此，
当我们的编译器看到print_typeof()调用，但还没有看到基于double实例
化的函数定义的时候，它只是假设在别处提供了这个定义，并产生一
个指向该定义的引用（让链接器利用该引用来解决这个问题）。另一
方面，当编译器处理文件 myfirst.cpp 的时候，它并没有指出：编译器
必须基于特定实参对所包含的模板定义进行实例化

*/
// use of the template
int main()
{
    double ice = 3.0;
    print_typeof(ice);  // call function template for type double
}
