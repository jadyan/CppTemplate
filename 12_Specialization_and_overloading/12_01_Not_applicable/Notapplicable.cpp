/*
 * @Author: your name
 * @Date: 2021-06-24 09:24:41
 * @LastEditTime: 2021-06-24 09:48:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_01_Not_applicable/Notapplicable.cpp
 */

#include <iostream>

using namespace std;
template<typename T>
class Array {
private:
	T* data;

public:
    Array():data()
    { 
        cout<<"构造"<<endl;
        data = new T();
    };
    virtual ~Array()
    {
        delete data;
    }
	Array(Array<T> const& temp);
	Array<T>& operator = (Array<T> const& temp);
	void exchange_with (Array<T>* b) 
	{
		T* tmp = data;
		data = b->data;
		b->data = tmp;
	}
	T& operator[] (size_t k) 
	{
		return data[k];
	}

    void set(T);
    void show();
};

template<typename T>
Array<T>::Array(Array<T> const& temp)
{
    this->data = temp.data;
}

template<typename T>
Array<T>& Array<T>::operator = (Array<T> const& temp)
{
    this->data = temp.data;
    return this;
}

template<typename T>
void Array<T>::set(T tmp)
{
    *data = tmp;
}

template<typename T>
void Array<T>::show()
{
    cout<<"this data : "<<*data<<endl;
}



template<typename T> inline
void exchange (T* a, T* b)
{
	T tmp(*a);
	*a = *b;
	*b = tmp;
}


/*
exchange()的泛型实现可以很好地处理。然而，
如果是针对需要进行繁重拷贝操作的类型，那么与给定结构的简单实
现（即exchange_with）相比，这种泛型实现无论从CPU的运转次数还
是内存的使用上讲，都可能是相当昂贵的了。在我们的例子中，该泛
型实现需要调用一次 Array<T>的拷贝构造函数和两次 Array<T>的拷贝
赋值运算符。对于大的数据结构，这些拷贝操作会涉及到拷贝巨大容
量的内存。然而， 我们通常可以用成员函数exchange_with 来替换
exchange()的功能，而且只需要交换Array<T>内部成员指针data。
*/

int main()
{
    Array<int> arr;
    arr.set(18);
    arr.show();

    Array<int> arr2;
    arr2.set(27);
    arr2.show();
cout<<"--------------"<<endl;
    arr.exchange_with(&arr2);
    arr.show();
    arr2.show();
    return 0;
}