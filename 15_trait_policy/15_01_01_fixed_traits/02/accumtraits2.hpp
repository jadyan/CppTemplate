/*
 * @Author: your name
 * @Date: 2021-06-25 13:55:31
 * @LastEditTime: 2021-06-25 13:56:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/15_trait_policy/15_01_01_fixed_traits/02/accumtraits2.hpp
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
template<typename T>
class AccumulationTraits;

/*
当为char时候，使用的是int
模板特化
*/
template<>
class AccumulationTraits<char> {
	public:
		   typedef int AccT;
};

template<>
class AccumulationTraits<short> {
	public:
		   typedef int AccT;
};

template<>
class AccumulationTraits<int> {
	public:
		   typedef long AccT;
};

template<>
class AccumulationTraits<unsigned int> {
	public:
		   typedef unsigned long AccT;
};

template<>
class AccumulationTraits<float> {
	public:
		   typedef double AccT;
};
