/*
 * @Author: your name
 * @Date: 2021-06-25 16:53:02
 * @LastEditTime: 2021-06-25 17:22:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_06_Template_parameters_and_member_templates/01/accum8.hpp
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
#include "sumpolicy2.hpp"
/*
template<typename,typename> class Policy = SumPolicy, 相当于一个参数，模板类声明  模板的模板参数？
typename Traits = AccumulationTraits<T> 根据前面的参数 生成新的参数


    这种利用模板的模板参数的解决方案也存在一个缺点：
    policy 类现在必须被写成模板，而且我们的接口中还定义了模板参数的
    确切个数。遗憾的是，这个定义会让我们无法在policy中添加额外的模
    板参数。例如，我们希望给SumPolicy添加一个Boolean型的非类型模板
    实参，从而可以选择是用 += 运算符来进行求和，还是只用 + 运算符来
    进行求和。在这个例子中，如果我们使用15.1.4小节的成员模板，那么
    只需要这样更改SumPolicy模板即可
*/

template <typename T,
          template<typename,typename> class Policy = SumPolicy,
          typename Traits = AccumulationTraits<T> >
class Accum {
  public:
    typedef typename Traits::AccT AccT;
    static AccT accum (T const* beg, T const* end) {
        AccT total = Traits::zero();
        while (beg != end) {
            Policy<AccT,T>::accumulate(total, *beg);
            ++beg;
        }
        return total;
    }
};

#endif // ACCUM_HPP
