14.5 泛型程序设计
静多态涉及到了泛型程序设计的概念。然而，对于泛型程序设
计，并没有一个统一的定义（就像面向对象的程序设计也没有统一的
定义一样）。根据[CzarneckiEiseneckerGenPorg]所言，这个概念涉及的
范围从使用泛型参数进行程序设计，一直到找出高效算法的最抽象表
述。该书总结如下：
泛型程序设计是计算机科学的一个分支，它运用自身系统的组
织，来找到高效的算法、数据结构和其他软件概念的抽象表述，以及
它们系统化的组织方式……泛型程序设计主要着重于表示一组相关的
领域概念（见该书的169和170页）。
在C++的上下文中，我们有时也把泛型程序设计定义为运用模板的
程序设计（就像面向对象的程序设计被看成是运用虚函数的程序设
计）。就这种意义而言，C++模板的每次使用都可以被看成是泛型程序
设计的一个实例；然而，开发人员却经常认为泛型程序设计本身具有
一个额外的本质特性：即在一个框架中，设计模板的目的是为了能够
得到多种有用的（类型）组合。
到目前为止，在C++泛型程序设计领域中，最显著的贡献就是
STL（Standard Template Library），它后来被采纳并引入到 C++标准库
中。STL 实际上是一个框架，它提供了许多有用的操作，我们也把这
些操作称为算法；它同时也为对象集合提供了许多线性数据结构，我
们把这些数据结构称为容器；而且，算法和容器都是模板。然而，关
键之处在于算法并不是容器的成员函数，而是以一种泛型的方式编写
的；因此任何容器（和线性的元素集合）都可以使用这些算法。为了
实现这个目的，STL的设计者引入了一个称为迭代器的抽象概念，任何
种类的线性容器都提供了这些迭代器。从本质上讲，容器在针对集合
方面的操作都被外包到迭代器的功能上了。
因此，如果要实现一个诸如计算序列中最大值的操作，我们并不
需要知道诸如这些值在序列中是如何存储的这样的细节：
template <class Iterator>
Iterator max_element (Iterator beg, // 指向容器的起始位置
Iterator end) // 指向容器的结束位置
{
// 只是使用迭代器的操作来遍历集合的所有元素
// 从而找到一个具有最大值的元素
// 并且以Iterator的形式返回这个元素的位置
…
}
在此，每个线性容器并不需要提供诸如max_element()的所有操
作，而只需要提供一个能够遍历序列中（它所包含的）所有值的迭代
器类型，和一些能够创建这类迭代器的成员函数：
namespace std {
template <class T, … >
class vector {
public:
typedef … const_iterator; // 为常量vector而特定实现的
… // 迭代器类型
const_iterator begin() const; // 表示容器起始位置的迭代器
const_iterator end() const; // 表示容器结束位置的迭代器
…
};
template <class T, ...>
class list {
public:
typedef … const_iterator; // 为常量list而特定实现的
… // 迭代器类型
const_iterator begin() const; // 表示容器开始位置的迭代器
const_iterator end() const; // 表示容器结束位置的迭代器
…
};
}
现在，你就可以通过调用泛型的max_element()操作，并且以容器
的开始位置和结束位置作为调用参数，来找到该容器的最大值（在此
我们省略了对空集合的特殊处理）：
// poly/printmax.cpp
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "MyClass.hpp"
template <typename T>
void print_max (T const& coll)
{
// 声明一个局部的容器迭代器
typename T::const_iterator pos;
// 计算出最大值的位置
pos = std::max_element(coll.begin(),coll.end());
//输出容器coll的最大元素的值（如果存在的话）
if (pos != coll.end()) {
std::cout << *pos << std::endl;
}
else {
std::cout << "empty" << std::endl;
}
}
int main()
{
std::vector<MyClass> c1;
std::list<MyClass> c2;
…
print_max (c1);
print_max (c2);
}
STL借助于迭代器对这些操作进行了参数化，从而避免了操作定义
在数量上的过度膨胀。在此，你并不需要为每个容器都实现每一个操
作，只需要实现某个算法一次，就可以把该算法应用到每个容器中。
换句话说，泛型程序设计的“粘合剂”就是：由容器提供的并且能被算
法所使用的迭代器。迭代器之所以能够肩负这样的任务，是由于容器
为迭代器提供了一些特定的接口，而算法所使用的正是这些接口。我
们通常也把每个这样的接口称为一个concept （即约束），它说明一个
模板（即容器）如果要并入这个框架（即 STL），就必须履行或者实
现这些约束。
从原则上讲，也可以使用动多态来实现这些类似于 STL 的功能。
然而，用多态实现的功能使用起来肯定会很受限制，因为与迭代器的
概念相比，动多态的虚函数调用机制将会是一种重量级的实现机制，
这就会对效率产生很大的影响。譬如增加一层基于虚函数的接口层，
通常就会影响操作的效率，而且这种影响的程度可能是几个数量级的
（甚至更加严重）。
事实上，泛型程序设计是相当实用的，因为它所依赖的是静多
态，而静多态会要求在编译期对接口进行解析。另一方面，这种要求
（即对接口在编译期进行解析）还会带来一些与面向对象程序设计原
则截然不同的新设计原则，在本书的剩余部分我们将会阐述许多重要
的泛型设计原则。