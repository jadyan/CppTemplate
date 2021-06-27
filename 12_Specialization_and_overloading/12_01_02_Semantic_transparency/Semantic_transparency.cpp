/*
 * @Author: your name
 * @Date: 2021-06-24 09:24:41
 * @LastEditTime: 2021-06-24 10:46:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /jadyan/code/book/CppTemplate/read/12_Specialization_and_overloading/12_01_Not_applicable/Notapplicable.cpp
 */



 /*
 在我们前面的例子中，成员函数 exchange_with()提供了一种替代
泛型函数 exchange()的有效方法；但是，要使用一个新的函数通常都会
带来一些不便之处：
12.1.2 语义的透明性
考虑上一小节中重载的用法，它对于获得实例化过程的透明自定
义是相当有用的；但更重要的是，我们应该知道这种透明性是（很大
程度上） 依赖于实现细节的。为了阐明这一点， 考虑我们的
quick_exchange()解决方案。虽然泛型算法和为 Array<T>类型自定义的
算法最后都可以交换指针所指向的值，但则两种算法各自所带来的边
缘效应却是截然不同的。
下面的代码交换了结构对象，同时也交换了Arrar<T>对象的值，
通过比较实现这两种交换的代码，我们可以很好地说明上面的这种不
同之处：
struct S {
	int x;
} s1, s2;

void distinguish (Array<int> a1, Array<int> a2)
{
	int* p = &a1[0];
	int* q = &s1.x;
	a1[0] = s1.x = 1;
	a2[0] = s2.x = 2;
	quick_exchange(&a1, &a2); // 在调用之后仍然有：*p == 1
	quick_exchange(&s1, &s2); // 调用之后*q == 2
}

我们从例子中可以看出，在调用quick_exchange()之后，指向第1个
Array的指针p变成了指向第2个Array的指针（即使值并没有改变）；然
而，指向non-Array（即struct）s1的指针在交换操作执行之后，仍然指
向s1，只是指针所指向的值发生了交换。这些区别已经是非常重要
的，也足以令模板实现的客户感到疑惑。对于前缀quick_而言，它可以
让用户感觉到这是一种实现所期望操作的快捷方式。然而，原来的泛
型exchange()模板还可以对Array<T>进行进一步的优化：
template<typename T>
void exchange(Array<T>* a, Array<T>* b)
{
	T* p = &(*a)[0];
	T* q = &(*b)[0];
	for (size_t k = a->size(); k-- != 0; ) {
	exchange(p++, q++);
}

与原来的泛型代码相比，这个版本的 exchange()的优点在于：并不
（ 潜在地） 需要庞大的临时 Array<T> 对象。我们可以对这个
exchange()模板进行递归调用，因此即使诸如Array<Array<char> >类型
的参数，也可以获得优化的性能。另外，我们看到这个特殊的模板版
本并没有声明为 inline，这是因为它本身会执行很多个（递归）操作；
相对而言，我们原来的泛型实现是内联的，因为它只执行很少的操作
（然而，每个操作都是昂贵的）。
 
 
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
        data = new T[10];
    };
    virtual ~Array()
    {
        //delete [] data;
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
    size_t size()
    {
        return 10;
    }
    void set(T);
    void show();
};

template<typename T>
Array<T>::Array(Array<T> const& temp)
{
    cout<<"拷贝构造"<<endl;
    this->data = temp.data;
}

template<typename T>
Array<T>& Array<T>::operator = (Array<T> const& temp)
{
    this->data = temp.data;
    return *this;
}

template<typename T>
void Array<T>::set(T tmp)
{
    //*data = tmp;
    for(int i=0;i<10;i++)
    {
        data[i] = tmp;
    }
}

template<typename T>
void Array<T>::show()
{
    cout<<"this data : "<<*data<<endl;
}


struct S {
	int x;
} s1, s2;


template<typename T> inline
void quick_exchange (T* a, T* b)
{
    cout<<"void quick_exchange (T* a, T* b) 调用"<<endl;
	T tmp(*a);
	*a = *b;
	*b = tmp;
}

/*
与原来的泛型代码相比，这个版本的 exchange()的优点在于：并不
（ 潜在地） 需要庞大的临时 Array<T> 对象。我们可以对这个
exchange()模板进行递归调用，因此即使诸如Array<Array<char> >类型
的参数，也可以获得优化的性能。另外，我们看到这个特殊的模板版
本并没有声明为 inline，这是因为它本身会执行很多个（递归）操作；
相对而言，我们原来的泛型实现是内联的，因为它只执行很少的操作
*/

#if 0
template<typename T> inline
void quick_exchange(Array<T>* a, Array<T>* b) 
{
    cout<<"void quick_exchange(Array<T>* a, Array<T>* b) 调用"<<endl;
    a->exchange_with(b);
}
#else
template<typename T>
void quick_exchange(Array<T>* a, Array<T>* b)
{
    cout<<"void quick_exchange(Array<T>* a, Array<T>* b) 调用"<<endl;
	T* p = &(*a)[0];
	T* q = &(*b)[0];
	for (size_t k = a->size(); k-- != 0; ) {
	    quick_exchange(p++, q++);
    }
}
#endif


void distinguish (Array<int> a1, Array<int> a2)
{
	int* p = &a1[0];
	int* q = &s1.x;
	a1[0] = s1.x = 1;
	a2[0] = s2.x = 2;
	quick_exchange(&a1, &a2); // 在调用之后仍然有：*p == 1
	quick_exchange(&s1, &s2); // 调用之后*q == 2  
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


cout<<"12_01_02 语义的透明性"<<endl;
    distinguish(arr,arr2);
    return 0;
}