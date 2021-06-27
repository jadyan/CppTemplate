/*
 * @Author: your name
 * @Date: 2021-06-24 09:24:41
 * @LastEditTime: 2021-06-24 10:09:26
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
void quick_exchange (T* a, T* b)
{
    cout<<"void quick_exchange (T* a, T* b) 调用"<<endl;
	T tmp(*a);
	*a = *b;
	*b = tmp;
}


template<typename T> inline
void quick_exchange(Array<T>* a, Array<T>* b) // (2)
{
    cout<<"void quick_exchange(Array<T>* a, Array<T>* b) 调用"<<endl;
    a->exchange_with(b);
}



/*
quick_exchange()的首次调用具有两个类型为int*的实参，因此只能
由第一个模板（即（1）处的声明）演绎成功，用int来替换T。因此，
在这里选择第一个模板，是毫无疑问的。相反，对于第二个调用，它
和两个模板都可以互相匹配：我们通过在第1个模板中用Array<int>替
换T、在第2个模板中用int来替换T，可以获得quick_exchange(p1, p2)的
两个可行函数；而且，这两种替换所获得的函数的参数类型和调用处
的实参类型也都可以精确匹配。通常而言，这将会使该调用产生二义
性，但是（我们将在后面讨论）C++语言认为第2个模板比第1个模板更
加特殊。因此，在其它条件都一样的情况下，重载解析规则会优先选
择更加特殊的模板，于是该调用选择（2）处的模板
*/


void demo(Array<int>* p1, Array<int>* p2)
{
	int x, y;
cout<<"quick_exchange(&x, &y)=>"<<endl;
	quick_exchange(&x, &y); // uses (1)
cout<<"quick_exchange(p1, p2)=>"<<endl;
	quick_exchange(p1, p2); // uses (2)
}


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

cout<<"12_01_01 透明自定义"<<endl;
    demo(&arr, &arr2);
    return 0;
}