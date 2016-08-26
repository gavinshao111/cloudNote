#include <iostream>  
#include <stdio.h>  
/* ȷ��ֵ�����ڴ���ֻ����һ�ݣ�ֵ������˼���ֵ��������ֵ��ַ��
 * ������������ֻ��һ��ֵ��ָ�롣������ʱ��Ҫ�жϻ���û�����������������ֵ��
 * StringRC�����涨��һ��ֵ��StringValue��ֵ�ඨ��һ�� char ָ��data��ָ���ַ�������һ��int refc����������
 * �����涨��һ��ֵ��ָ��sv�����๹��ʱ��new һ��ֵ�����
 * �����ã����ÿ������캯����ʱ����ֵ�����svָ���������ֵ�����Ȼ��sv->refc++
 * ������ʱ�����ж�sv->refc�Ƿ�Ϊ0��delete sv
 * ��ֵ���������أ����ж��Ƿ�Ϊͬһ�����á����жϵ�ǰֵ����û���������ã�û�о�delete sv��Ȼ��svָ��������sv��sv->refc++
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
  
    StringValue *value;//���е����ö��������Ψһһ��value��value����ʵ�ʴ洢data�����ô���  
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
  
String::String(const String &rhs) {//Ҫ�����ü�1  
    value = rhs.value;  
    value->refCount++;//����ָ��ͬһ��data�Ķ�������ü�1  
}  
  
String &String::operator =(const String &rhs) {  
    if (value == rhs.value)//ע�⣬����this == &rhs  
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