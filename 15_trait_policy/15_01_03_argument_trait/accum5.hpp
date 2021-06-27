/*
 * @Author: your name
 * @Date: 2021-06-25 14:50:58
 * @LastEditTime: 2021-06-25 15:01:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_03_argument_trait/accum5.hpp
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
#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits4.hpp"


/*
大多数使用这个模板的用户都不必显式地提供第2个模
板实参，因为我们可以针对第1个实参的类型，为每种类型都配置一个
合适的缺省值
*/
template <typename T, typename AT = AccumulationTraits<T> >
class Accum {
  public:
    static typename AT::AccT accum (T const* beg, T const* end)
    {
#if 0
        typedef  typename AT::AccT  AccT;
        AccT total = AT::zero();
#else
        typename AT::AccT total = AT::zero();
#endif
        while (beg != end) {
            total += *beg;
            ++beg;
        }
        return total;
    }
};

/*
当使用类对象时候
我们可以引入一个辅助函数，来简化上面基于类的接口：

*/

template <typename T>
inline
typename AccumulationTraits<T>::AccT accum (T const* beg, T const* end)
{
	return Accum<T>::accum(beg, end);
}


template <typename Traits, typename T>
inline
typename Traits::AccT accum (T const* beg, T const* end)
{
	return Accum<T, Traits>::accum(beg, end);
}

#endif // ACCUM_HPP
