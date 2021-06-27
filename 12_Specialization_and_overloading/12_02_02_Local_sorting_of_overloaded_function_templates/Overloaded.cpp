/*
 * @Author: your name
 * @Date: 2021-06-24 13:56:27
 * @LastEditTime: 2021-06-24 13:56:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_02_02_Local_sorting_of_overloaded_function_templates/Overloaded.cpp
 */
/*
12.2.2 重载的函数模板的局部排序
重新考虑我们前面的例子：
#include <iostream>
template<typename T>
int f(T)
{
	return 1;
}
template<typename T>
int f(T*)
{
	return 2;
}
int main()
{
	std::cout << f<int*>((int*)0) << std::endl;
	std::cout << f<int>((int*)0) << std::endl;
}
我们发现：用给定的模板实参列表（<int*>和<int>）进行替换之
后，重载解析最后会选择一个最佳的函数并进行调用。然而，即使在
没有提供显式模板实参的情况下，也会有一个函数被选中。在这种情
况下，就是模板实参演绎起作用的时候了。让我们稍微修改前面例子
的main()函数，来讨论这种机制：
#include <iostream>
template<typename T>
int f(T)
{
	return 1;
}
template<typename T>
int f(T*)
{
	return 2;
}
int main()
{
	std::cout << f(0) << std::endl;
	std::cout << f((int*)0) << std::endl;
}
让我们先考虑调用(f(0))：实参的类型是int，如果用int替换T，就
能和第1个模板的参数匹配。然而，第2个模板的参数类型总是一个指
针；因此，经过演绎之后，只有产生自第1个模板的实例才是该调用的
候选函数。在这个调用中，重载解析并没有发挥作用。
	
第2个调用((f ( (int*) 0) )就显得比较有趣：对于这两个模板，实参
演绎都可以获得成功，于是就获得两个函数，即f<int*>(int*)和f<int>
(int*)。如果根据原来的重载解析观点，这两个函数和实参类型为 int*
的调用的匹配程度是一样的，这也就意味着该调用是二义性的（见附
录B）。然而，在这种情况下，还应该考虑重载解析的额外规则：选
择“产生自更特殊的模板的函数”。因此（我们将在后面的小节看
到），第2个模板被认为是更加特殊的模板，从而（再次）产生下面的
输出结果：1
2
*/


#include <iostream>
template<typename T>
int f(T)
{
	return 1;
}
template<typename T>
int f(T*)
{
	return 2;
}
int main()
{
	std::cout << f(0) << std::endl;
	std::cout << f((int*)0) << std::endl;
}