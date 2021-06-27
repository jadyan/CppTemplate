/*
 * @Author: your name
 * @Date: 2021-06-24 15:05:22
 * @LastEditTime: 2021-06-24 15:15:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_03_03_glob_member_temp_speciali/member.cpp
 */
#include <iostream>

template<typename T>
class Outer { // (1)
	public:
	template<typename U>
	class Inner { // (2)
		private:
            static int count; // (3)
	};
	static int code; // (4)
	void print() const { // (5)
		std::cout << "generic"<<std::endl;
	}
};
template<typename T>
int Outer<T>::code = 6; // (6)

template<typename T>
template<typename U>
int Outer<T>::Inner<U>::count = 7; // (7)


template<>
class Outer<bool> { // (8)
	public:
	template<typename U>
	class Inner { // (9)
		private:
		static int count; // (10)
	};
	void print() const { // (11)
        std::cout << "Outer<bool>"<<std::endl;
	}
};

/*
成员函数特化
*/
template<>
int Outer<void>::code = 12;

template<>
void Outer<void>::print() const
{
    std::cout << "Outer<void>"<<std::endl;
}

int main()
{
    Outer<int> q;
    q.print();

    Outer<bool> bq;
    bq.print();

    Outer<void> vq;
    vq.print();

    return 0;
}