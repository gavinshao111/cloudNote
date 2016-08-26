#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class MyString{
public:
    //构造函数 默认参数NULL
    MyString(const char* s = NULL){
	if (NULL == s)
	    m_data = NULL;
	else{
	    m_data = new char[strlen(s)+1];
	    strcpy(m_data, s);	    
	}
    }
    
    //析构函数
    ~MyString(){
	delete m_data;
    }
    
    //复制构造函数
    MyString(const MyString &MyS){
	if (NULL == MyS.m_data)
	    m_data = NULL;
	else{
	    m_data = new char[strlen(MyS.m_data)+1];
	    strcpy(m_data, MyS.m_data);	    
	}
    }
    
    //=重载 考虑参数对象与当前对象相等的情况
    MyString &operator=(const MyString &MyS){
	if (&MyS == this)
	    return *this;
	delete m_data;
	if (NULL == MyS.m_data)
	    m_data = NULL;
	else {
	    m_data = new char[strlen(MyS.m_data)+1];
	    strcpy(m_data, MyS.m_data);
	}
	return *this;
    }
    //+重载 考虑两个对象的 m_data 都为空的情况
    MyString operator+(const MyString &MyS){
	if (NULL == MyS.m_data)
	    return *this;
	if (NULL == m_data)
	    return MyS;
	MyString newStr;
	newStr.m_data = new char[strlen(m_data)+strlen(MyS.m_data)+1];
	strcat(newStr.m_data, this->m_data);
	strcat(newStr.m_data, MyS.m_data);
	return newStr;
    }
    //==重载
    bool operator==(const MyString &MyS)const{ //函数后加 const 表示函数不改变成员变量
	return strcmp(m_data, MyS.m_data)==0?true:false;
    }
    //[]重载
    char &operator[](int &n)const{
	if(n<0||strlen(m_data)<n){
	    cout<<"error in MyString::operator[]"<<endl;
	    exit(1);
	}
	return m_data[n];
    }
    void print(void){
	cout<<m_data<<endl;
    }
private:    
    char *m_data;
};
int main(void)
{
    MyString *a = new MyString("123");
    cout<<"a: ";
    a->print();
    MyString b("4567");
    cout<<"b: ";
    b.print();
    MyString c(*a);
    cout<<"c: ";
    c.print();
    b = b+c;
    cout<<"b: ";
    b.print();
    cout<<(b==c)<<endl;


    return 0;
}
