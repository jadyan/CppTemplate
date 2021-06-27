/*
 * @Author: your name
 * @Date: 2021-06-25 16:04:14
 * @LastEditTime: 2021-06-25 16:22:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_04_policy_policyclass/02/accum6.hpp
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
#include "sumpolicy1.hpp"

template <typename T,
          typename Policy = SumPolicy,
          typename Traits = AccumulationTraits<T> >
class Accum {
  public:
    typedef typename Traits::AccT AccT;
    static AccT accum (T const* beg, T const* end) {
        AccT total = Traits::zero();
        while (beg != end) {
            Policy::accumulate(total, *beg);
            ++beg;
        }
        return total;
    }
};

template <typename T>
inline
typename AccumulationTraits<T>::AccT accum (T const* beg, T const* end)
{
	return Accum<T>::accum(beg, end);
}


template <typename Traits, typename Tpolicy, typename T>
inline
typename Traits::AccT accum (T const* beg, T const* end)
{
	return Accum<T, Tpolicy, Traits>::accum(beg, end);
}


#endif // ACCUM_HPP
