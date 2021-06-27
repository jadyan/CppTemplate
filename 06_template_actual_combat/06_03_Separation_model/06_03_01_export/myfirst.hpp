/*
 * @Author: your name
 * @Date: 2021-06-16 21:32:13
 * @LastEditTime: 2021-06-16 21:52:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/06_template_actual_combat/06_03_Separation_model/06_03_01_export/myfirst.hpp
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
#ifndef MYFIRST_HPP
#define MYFIRST_HPP

// declaration of template
export template <typename T> 
void print_typeof (T const&);

#endif // MYFIRST_HPP
