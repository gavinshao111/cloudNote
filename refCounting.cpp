#include <iostream>  
#include <stdio.h>  
/* 确保值类在内存中只存在一份，值类包含了计数值和真正的值地址。
 * 所以在类里面只是一个值类指针。在析构时，要判断还有没有其他对象引用这个值。
 * StringRC类里面定义一个值类StringValue，值类定义一个 char 指针data，指向字符串，和一个int refc用来计数。
 * 类里面定义一个值类指针sv，当类构造时，new 一个值类对象。
 * 当引用（调用拷贝构造函数）时，将值类对象sv指向引用类的值类对象，然后sv->refc++
 * 析构类时，先判断sv->refc是否为0再delete sv
 * 赋值操作符重载，先判断是否为同一个引用。再判断当前值还有没有其他引用，没有就delete sv。然后sv指向参数类的sv，sv->refc++
 */
using namespace std;  
  
class String {  
public:  
    String(const char *pdata);  
    String(const String &rhs);  
    String &operator = (const String &rhs);  
    ~String();  
private:  
    class StringValue {  
    public:  
        int refCount;  
        char *data;  
        StringValue(const char *pdata);  
        ~StringValue();  
    };  
  
    StringValue *value;//所有的引用对象均共享唯一一个value，value里面实际存储data和引用次数  
};  
  
String::StringValue::StringValue(const char *pdata):refCount(1) {  
    data = new char[strlen(pdata) + 1];  
    strcpy(data,pdata);  
}  
  
String::StringValue::~StringValue() {  
    delete [] data;  
}  
  
String::String(const char *pdata):value(new StringValue(pdata))  
{}  
  
String::String(const String &rhs) {//要对引用加1  
    value = rhs.value;  
    value->refCount++;//所有指向同一段data的对象的引用加1  
}  
  
String &String::operator =(const String &rhs) {  
    if (value == rhs.value)//注意，不是this == &rhs  
        return *this;  
    if(--value->refCount == 0)  
        delete value;  
  
    value = rhs.value;  
    ++value->refCount;  
  
    return *this;  
}  
  
String::~String() {  
    if (--value->refCount == 0)  
        delete value;  
}  
  
void test() {  
    String ss("ssss");  
    String s1 = ss;  
    String s2("dddd");  
    s2 = ss;  
}  
  
int main() {  
    test();  
}  