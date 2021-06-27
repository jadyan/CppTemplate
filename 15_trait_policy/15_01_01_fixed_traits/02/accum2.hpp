/*
 * @Author: your name
 * @Date: 2021-06-25 13:46:31
 * @LastEditTime: 2021-06-25 13:57:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_01_fixed_traits/02/accum2.hpp
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

#include "accumtraits2.hpp"

//返回是 AccumulationTraits<T>::AccT 
template <typename T>
inline
typename AccumulationTraits<T>::AccT accum (T const* beg, 
                                            T const* end)
{
    // return type is traits of the element type
    //返回值的类型是一个元素类型的trait
    /*
        受限类型必须加typename
    */
    typedef typename AccumulationTraits<T>::AccT AccT;

    AccT total = AccT();  // assume AccT() actually creates a zero value
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

#endif // ACCUM_HPP
