/*
 * @Author: your name
 * @Date: 2021-06-25 16:01:47
 * @LastEditTime: 2021-06-25 16:32:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_04_policy_policyclass/02/accum7.cpp
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
#include "accum6.hpp"
#include <iostream>

class MultPolicy {
  public:
    template<typename T1, typename T2>
    static void accumulate (T1& total, T2 const& value) {
        total *= value;
    }
};


/*
即这个policy可以使用实现zero()的trait，也可以不使
用这个trait。然而，我们应该知道，实际上还存在其他的解决方案：即
并不是所有的问题都必须由trait和policy来解决的
*/
int main()
{
    // create array of 5 integer values
    int num[] = { 1, 2, 3, 4, 5 };

#if 0
    // print product of all values
    std::cout << "the product of the integer values is "
              << Accum<int,MultPolicy>::accum(&num[0], &num[5])
              << '\n';
#else
    //使用简化函数来调用
    std::cout << "the product of the integer values is "
              << accum<AccumulationTraits<int>, MultPolicy, int>(&num[0], &num[5])
              << '\n';
    
    //指定为int
    std::cout << "defult the product of the integer values is "
              << accum<int>(&num[0], &num[5])
              << '\n';
    //全部使用推导
    std::cout << "all defult the product of the integer values is "
              << accum(&num[0], &num[5])
              << '\n';
#endif
}
