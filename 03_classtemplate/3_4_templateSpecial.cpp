#include <iostream>
using namespace std;

/*
 *那模板的偏特化呢？所谓的偏特化是指提供另一份template定义式，而其本身仍为templatized；
也就是说，针对template参数更进一步的条件限制所设计出来的一个特化版本。这种偏特化的应用在STL中是随处可见的。

特化是指将所有的模板参数进行替换成具体类型，而偏特化是指将部分参数类型指定为具体类型。
www.jianshu.com/p/4be97bf7a3b9者：zhaozhengcoderd4d
https://zhuanlan.zhihu.com/p/104615732
https://www.cnblogs.com/yyehl/p/7253254.html
 *
 *
 *
 * */

// 一般化设计
template <class T, class T1>
class TestClass
{
public:
     TestClass()
     {
          cout<<"T, T1"<<endl;
     }
};

// 针对普通指针的偏特化设计
template <class T, class T1>
class TestClass<T*, T1*>
{
public:
     TestClass()
     {
          cout<<"T*, T1*"<<endl;
     }
};

// 针对const指针的偏特化设计
template <class T, class T1>
class TestClass<const T*, T1*>
{
public:
     TestClass()
     {
          cout<<"const T*, T1*"<<endl;
     }
};

template <class T, class T1>
class TestClass<const T*, const T1*>
{
public:
	TestClass()
	{
		cout<<"const T*, const T1*"<<endl;
	}	
};

int main()
{
     TestClass<int, char> obj;
     TestClass<int *, char *> obj1;
     TestClass<const int *, char *> obj2;
	 TestClass<const int * , const int*> obj3;

     return 0;
}

