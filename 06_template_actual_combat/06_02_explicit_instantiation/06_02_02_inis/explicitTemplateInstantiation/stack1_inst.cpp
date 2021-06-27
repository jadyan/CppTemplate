/*
 * @Author: your name
 * @Date: 2021-06-16 20:46:58
 * @LastEditTime: 2021-06-16 20:56:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/06_template_actual_combat/06_02_explicit_instantiation/06_02_02_inis/explicitTemplateInstantiation/stack1_inst.cpp
 */
#include "stack1def.hpp"
#include <string>

template class Stack<int>;


/*
对于每个不同实体，在一个程序中最多只能有一个显式实例化
体， 换句话说， 你可以同时显式实例化 print_typeof<int> 和
print_typeof<double>[23]，但在同一个程序中每个指示符都只能够出现
一次[24]。如果不遵循这条规则，通常都会导致链接错误，链接器会报
告：发现了实例化实体的重复定
page 109
*/
#if 1
template class Stack<std::string>;
#else
template Stack<std::string>::Stack();
template void Stack<std::string>::push(std::string const&);
template std::string Stack<std::string>::top()const;
template void Stack<std::string>::pop();
#endif
