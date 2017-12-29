	1. stringstream 用来代替 sprintf, atoi, atof

stringstream stream;
string result;
int i = 1000;
stream << i; //将int输入流
stream >> result; //从stream中抽取前面插入的int值

清空 stringstream 内容必须调用 stringstream::str("") 而非 stringstream::clear();

ref: http://blog.csdn.net/beyondlpf/article/details/7680760


	2. regex
	
const char* mail = "tengxun@qq.com";
boost::cmatch res;

//建立3个子表达式
boost::regex reg("(\\w+)@(\\w+).(\\w+)");
if (boost::regex_match(mail,res, reg))
{
	//既可以通过迭代器获取数据， 也可以通过数组方式获取数据
	for (boost::cmatch::iterator pos = res.begin(); pos != res.end(); ++pos)
	{
	    std::cout << *pos << std::endl;
	}
	//res[0]存放匹配到的完整字符串
	std::cout << "name:" << res[1] << std::endl;
}
output：
tengxun@qq.com
tengxun
qq
com
name:tengxun


	3. ref

void T1Task(A& a);

A a;
将调用5次复制构造函数
boost::thread boostT1(T1Task, a);
将调用3次复制构造函数
std::thread stdT(T1Task, a);
而用了ref，不调用复制构造函数，直接传递引用对象
std/boost::thread stdT(T1Task, std::ref<A>(a));

	std::ref 与 std::cref 的区别：std::cref传入对象为const

4. boost::thread
主线程调用子线程的 interrupt
子线程如果在中断点则抛出 boost::thread_interrupted 异常

5. 当封装没有命名空间的c函数，又出现函数重名的时候，调用c函数同名前加 :: 可以解决。


6. boost::tcp
不管是 boost::asio::async_write 还是 boost::asio::write 还是 boost::asio::ip::tcp::socket::write_some
在对方关闭socket后，总是能写成功，不抛任何异常

7. std sleep
#include <iostream>
#include <chrono>
#include <thread>
 
int main()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

8. std::fstream

	ifstream ifs("123.log");
	while(!ifs.eof()) {
		char buf[128] = {0};
		ifs.read(buf, 10);
		cout << "read " << ifs.gcount() << " bytes: " << buf << endl;
	}
	ifs.close();

9. time string
#define TIMEFORMAT "%Y-%m-%d %H:%M:%S"
string timeToStr(const time_t& time) {
    struct tm* timeTM;
    char strTime[22] = {0};
    
    timeTM = localtime(&time);
    strftime(strTime, sizeof (strTime) - 1, TIMEFORMAT, timeTM);
    string timeStr(strTime);
    return timeStr;
}

10. shared_ptr
	定义后没有用make_shared或new构造，共享指针对象为空 且 use_count() == 0
	用make_shared或new构造后，共享指针对象非空。
	调用reset()后共享指针对象为空 且 use_count() == 0
