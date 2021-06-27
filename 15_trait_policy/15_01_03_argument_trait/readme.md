15.1.3 参数化trait
在上一节所使用的trait被称为fixed trait，因为一旦定义了这个分离
的trait，就不能在算法中对它进行改写。然而，在有些情况下我们需要
对trait进行改写。例如，我们可能偶然发现可以对一组float值进行求
和，然后很安全地把和值存储在一个具有相同类型（即float型）的变量
里面，而且这样通常能够给我们带来更高的效率。
从原则上讲，参数化trait主要的目的在于：添加一个具有缺省值的
模板参数，而且该缺省值是由我们前面介绍的trait模板决定的。在这种
具有缺省值的情况下，许多用户就可以不需要提供这个额外的模板实
参；但对于有特殊需求的用户，也可以改写这个预设的和类型。对于
这个特殊的解决方案，唯一的不足在于：我们并不能对函数模板预设
缺省模板实参[7]。
就现在的情况而言，通过把算法实现为一个类，我们就可以绕过
上面这个不足。这同时也说明了：除了函数模板之外，在类模板中也
可以很容易地使用trait。在我们的应用程序中，唯一的缺点就是：类模
板不能对它的模板参数进行演绎，而是必须显式提供这些模板参数。
因此，我们需要编写如下形式的代码：
Accum<char>::accum(&name[0], &name[length])
才能使用我们修改后的求和模板：
// traits/accum5.hpp
#ifndef ACCUM_HPP
#define ACCUM_HPP
#include "accumtraits4.hpp"
template <typename T,
typename AT = AccumulationTraits<T> >
class Accum {
public:
static typename AT::AccT accum (T const* beg, T const* end) {
typename AT::AccT total = AT::zero();
while (beg != end) {
total += *beg;
++beg;
}
return total;
}
};
#endif // ACCUM_HPP
通常而言，大多数使用这个模板的用户都不必显式地提供第2个模
板实参，因为我们可以针对第1个实参的类型，为每种类型都配置一个
合适的缺省值。
和大多数情况一样，我们可以引入一个辅助函数，来简化上面基
于类的接口：
template <typename T>
inline
typename AccumulationTraits<T>::AccT accum (T const* beg,
T const* end)
{
	return Accum<T>::accum(beg, end);
}
template <typename Traits, typename T>
inline
typename Traits::AccT accum (T const* beg, T const* end)
{
	return Accum<T, Traits>::accum(beg, end);
}

