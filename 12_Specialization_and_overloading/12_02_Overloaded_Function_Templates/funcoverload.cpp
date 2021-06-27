/*
 * @Author: your name
 * @Date: 2021-06-24 13:20:01
 * @LastEditTime: 2021-06-24 13:20:01
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_02_Overloaded_Function_Templates/funcoverload.cpp
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
/*
12.2 重载函数模板
在上一节，我们看到两个同名的函数模板可以同时存在，还可以
对它们进行实例化，使它们具有相同的参数类型。下面是另一个简单
的例子：
// details/funcoverload.hpp
template<typename T>
int f(T)
{
return 1;
}
template<typename T>      cp
int f(T*)
{
return 2;
}
如果我们用int*来替换第1个模板的T，用int来替换第2个模板的T，
那么将会获得两个具有相同参数类型（和返回类型）的同名函数。也

就是说，不仅是同名模板可以同时存在，它们各自的实例化体[56]也可
以同时存在，即使这些实例化体具有相同的参数类型和返回类型。
下面的代码说明了：如何通过显式模板实参语法，来调用这两个
生成的函数（假设存在前面的模板声明）：
//details/funcoverload cpp
#include <iostream>
#include "funcoverload.hpp"
int main()
{
std::cout << f<int*>((int*)0) << std::endl;
std::cout << f<int>((int*)0) << std::endl;
}
程序的输出如下：1
2
为了说明这一点，让我们详细地分析调用f<int*>((int*)0)[57]。语
法f<int*>说明我们希望用int*来替换模板f的第1个模板参数，而且这种
替换并不依赖于模板实参演绎。在这个例子中，有两个f模板，因此所
生成的重载集包含了两个函数：f<int*>(int*)（生成自第一个模板）和
f<int*>(int**)（生成自第2个模板）。然而，调用实参(int*)0的类型是
int*，因此它将会和第1个模板生成的函数更好地匹配，最后也就调用
这个函数。


*/


#include <iostream>
#include "funcoverload.hpp"

int main() 
{
    std::cout << f<int*>((int*)0) << std::endl;
    std::cout << f<int>((int*)0)  << std::endl;
}
