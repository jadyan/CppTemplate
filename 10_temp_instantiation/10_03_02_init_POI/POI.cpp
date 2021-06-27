/*
 * @Author: your name
 * @Date: 2021-06-23 16:02:30
 * @LastEditTime: 2021-06-23 17:05:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/10_temp_instantiation/10_03_02_init_POI/POI.cpp
 */

#include <iostream>


/*
https://blog.csdn.net/u012481976/article/details/84345912

https://xyfu.me/posts/1ba55501/
point of instantiation， 实例化点
从上面我们知道， C++编译器会在模板客户端代码中的某些位置访问模板实体的声明或者定义。 于是， 当某些代码构造引用了模板特化，而且为了生成这个完整的特化，
需要实例化相应模板的定义时， 就会在源代码中产生一个实例化点（POI） 。 我们应该清楚， POI是位于源代码中的一个点， 在该点会插入替换后的模板实例。




第一阶段：解析模板

    在 非待决名 上使用 有限定的名字查找 或 无限定的名字查找。
    在 无限定的待决名 上使用无限定的名字查找，确认其是否是一个模板。然而我们在第一阶段不进行ADL。ADL被推迟到第二阶段。我们认为此次查找的结果暂时是不完整的。
    此时无法处理有限定的待决名。
    第二阶段：模板实例化

在实例化点(POI: point of instantiation)对模板进行实例化。
    对 有限定的待决名 进行 有限定的名字查找
    对 无限定的待决名 进行 ADL 将结果与第一阶段进行的 无限定的名字查找 的结果合并

*/
class MyInt {
    public:
    MyInt(int i){ };
};


MyInt operator - (MyInt const&)
{
}
bool operator > (MyInt const&, MyInt const&)
{
}
typedef MyInt Int;


//void g(Int);

template <typename T>
void f(T i)
{
    if (i > 0) 
    {
        g(-i);
    }
}

/*

当C++编译器看到调用f<Int>(42)时， 它知道需要用MyInt替换T来实例化模板f： 即生成一个POI。 
（2） 处和（3） 处是临近调用点的两个地方， 但它们不能作为POI， 因为C++并不允许我们把::f<Int>(Int)的定义在这里插入。 
另外， （1） 处和（4） 处的本质区别在于： 在（4） 处，函数 g(Int)是可见的， 而（1） 处则不是； 因此在（4） 处函数 g(-i)可以被解析。
 然而， 如果我们假定（1） 处作为POI， 那么调用g(-i)将不能被解析， 因为g(Int)在（1） 处是不可见的。 幸运的是， 对于指向非类型（也就是函数）特化的引用，
  C++把它的POI定义在“包含这个引用的定义或声明之后的最近名字空间域”中。 在我们的例子中， 这个位置是（4）

*/

//(1)
void g(Int)
{
    //(2)
    f<Int>(42); //调用点
    //(3)
}
//(4)

int main (int argc, char ** argv)
{
    g(18);
    //f(27);
    return 0;
}