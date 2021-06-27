/*
 * @Author: your name
 * @Date: 2021-06-25 14:28:24
 * @LastEditTime: 2021-06-25 14:29:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_02_value_trait/02/accumtraits4.hpp
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

 /*
  唯一的区别只是这里使用了函数调用语
  法（而不是访问一个静态数据成员）：
  AccT total = AccumulationTraits<T>::zero();
  显然，trait 还可以代表更多的类型。在我们的例子中，trait 可以是
  一个机制，用于提供accum()所需要的、关于元素类型的所有必要信
  息；实际上，这个元素类型就是调用 accum()的类型，即模板参数的类
  型。下面是trait概念的关键部分：trait提供了一种配置具体元素（通常
  是类型）的途径，而该途径主要是用于泛型计算。
 */

template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char> {
  public:
    typedef int AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<short> {
  public:
    typedef int AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<int> {
  public:
    typedef long AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<unsigned int> {
  public:
    typedef unsigned long AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<float> {
  public:
    typedef double AccT;
    static AccT zero() {
        return 0.0;
    }
};
//...
