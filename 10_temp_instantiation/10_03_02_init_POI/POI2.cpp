/*
 * @Author: your name
 * @Date: 2021-06-23 16:48:42
 * @LastEditTime: 2021-06-23 16:50:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/10_temp_instantiation/10_03_02_init_POI/POI2.cpp
 */



/*
我们知道f<double>的POI会在（2）处。 但在这个例子中， 函数模板f()引用了一个类特化S<char>； 从前面的讨论我们知道，
该类特化的POI应该在（1）处。 另外， 函数模板f()还引用了S<T>； 因为S<T>是依赖型的， 所以我们不能像S<char>那样来确定它的POI。
然而， 如果在(2)处实例化了f<double>， 我们知道同时需要实例化S<double>的定义。 对于类型实体和非类型实体， 这种二次（或者传递） POI（指S<double>的POI） 的定义位置稍微有些区别。 
对于非类型实体， 这种二次POI的位置和主POI（指f<double>）的位置相同。 对于类型实体， 二次POI的位置位于主POI（指f<double>）位置的紧前处（最近的名字空间域内）。
在我们的例子中，利用前面的规则，f<double>的POI位于（2b）处， 而在它的紧前处(即（2a）处)，就是二次POI（即S<double>的POI） 的位置。 现在我们就知道S<double>和S<char>的POI是不同的。

一个翻译单元通常会包含同个实例的多个 POI。 对于类模板实例而言， 在每个翻译单元中， 只有首个POI会被保留， 而其他的POI则被忽略（其实它们并不会被认为是POI） 。 
对于非类型实例而言， 所有的POI都会被保留。

 
*/
template<typename T>
class S {
public:
	typedef int I;
};
//(1)
template<typename T>
void f()
{
	S<char>::I var1 = 41;
	typename S<T>::I var2 = 42;
}
int main()
{
	f<double>();
} //(2) ,此处分为: (2a), (2b)
