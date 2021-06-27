/*
 * @Author: your name
 * @Date: 2021-06-25 14:12:51
 * @LastEditTime: 2021-06-25 14:18:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_02_value_trait/01/accum3.hpp
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

#include "accumtraits3.hpp"

template <typename T>
inline
typename AccumulationTraits<T>::AccT accum (T const* beg,
                                            T const* end)
{
    // return type is traits of the element type
    typedef typename AccumulationTraits<T>::AccT AccT;

    /*
    初始值为0
    前面的accum()模板使用了缺省构造函数的返回值来初始化结
    果变量（即total），而且我们期望该返回值是一个类似0的值：
    AccT total = AccT(); // 假设AccT() 实际上生成了一个0值
    …
    return total;
    显然，我们并不能保证上面的构造函数会返回一个符合条件的
    值，可以用来开始这个求和循环。而且，类型AccT也不一定具有一个
    缺省构造函数
    */
    AccT total = AccumulationTraits<T>::zero;
    //AccT total = AccT();

    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

#endif // ACCUM_HPP

