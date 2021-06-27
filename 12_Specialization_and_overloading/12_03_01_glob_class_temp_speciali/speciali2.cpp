/*
 * @Author: your name
 * @Date: 2021-06-24 14:33:57
 * @LastEditTime: 2021-06-24 14:36:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_03_01_glob_class_temp_speciali/speciali2.cpp
 */
#include <iostream>

template<typename T> class S;

template<> class S<char**> {
	public:
	void print() const;
};
//下面的定义不能使用template<>前缀
void S<char**>::print() const
{
std::cout << "pointer to pointer to char\n";
}




template<typename T>
class Outside {
public:
	template<typename U>
	class Inside 
	{
	};
};

template<>
class Outside<void> {
// 下面的嵌套类和前面定义的泛型模板之间并不存在联系
	template<typename U>
	class Inside {
		private:
		static int count;
	};
};


//下面的定义不能使用template<>前缀
template<typename U>
int Outside<void>::Inside<U>::count = 1;

int main()
{
    return 0;
}