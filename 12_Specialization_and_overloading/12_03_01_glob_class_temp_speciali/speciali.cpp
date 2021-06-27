/*
 * @Author: your name
 * @Date: 2021-06-24 14:21:39
 * @LastEditTime: 2021-06-24 14:28:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_03_01_glob_class_temp_speciali/speciali.cpp
 */

#if 0
template<typename T>
class S {
	public:
	void info() 
	{
		std::cout << "generic (S<T>::info())\n";
	}
};
template<>
	class S<void> {
	public:
	void msg() 
	{
		std::cout << "fully specialized (S<void>::msg())\n";
	}
};
#endif

template<typename T>
class Types {
	public:
	typedef int I;
};

//template<typename T, typename U = typename Types<T>::I> class S; // (1)
template<typename T, typename U = typename Types<T>::I> 
class S
{
    public:
	void f();
};

template<>
class S<void> 
{ // (2)
	public:
	void f();
};

//template<> class S<char, char>; // (3)
//template<> class S<char, 0>; // 错误：不能用0来替换U

template<> 
class S<char, char>
{
    public:
	void f();
};
///template<> class S<char, 0>; // 错误：不能用0来替换U

int main()
{
	S<int>* pi; 
	S<int> e1; 
	S<void>* pv;
	S<void,int> sv; 
	S<void,char> e2; 
	S<char,char> e3; 
}