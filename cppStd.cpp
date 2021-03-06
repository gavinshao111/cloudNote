	1. stringstream 用来代替 sprintf, atoi, atof

stringstream stream;
string result;
int i = 1000;
stream << i; //将int输入流
stream >> result; //从stream中抽取前面插入的int值

清空 stringstream 内容必须调用 stringstream::str("") 而非 stringstream::clear();

ref: http://blog.csdn.net/beyondlpf/article/details/7680760


	2. regex
	
\w 匹配包括下划线的任何单词字符。等价于'[A-Za-z0-9_]'
	
	
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

string t = "20031215T144307Z";
std::cmatch res;
std::regex reg("(\\d{4})(\\d{2})(\\d{2})T(\\d{2})(\\d{2})(\\d{2})Z");
if (std::regex_match(t.c_str(), res, reg)) {
    for (auto it : res)
        cout << it << endl;
}
output:
20031215T144307Z
2003
12
15
14
43
07

2018-01-12_141438_0278.mp4
"^\\d{4}\\-\\d{2}\\-\\d{2}\\_\\d{6}\\_\\d{4}\\.mp4" or "\\d{4}-\\d{2}-\\d{2}_\\d{6}_\\d{4}.mp4"

ANNOUNCE rtsp://120.26.86.124:8888/record/20180131132928/1/0/2018-02-05_092500_0300.sdp RTSP/1.0\r\n\r\nContent-Type: application/sdp\r\n\r\nCSeq: 2\r\n\r\nUser-Agent: LeapMotor Push v1.0\r\n\r\nContent-Length: 297\r\n\r\n\r\n
^([a-zA-Z]+) (rtsp://[^/]+/(([a-z]+)/(\\S+)/(\\d)/(\\d+)/(\\S+).sdp))[\\s\\S]+User-Agent:[ ]*(.+)[\\s\\S]+

匹配双字节字符(包括汉字在内)：[^\x00-\xff]

贪婪/懒惰
[09:18:27:183] [INFO] - com.leapmotor.emqservice.service.impl.VehicleFaultService.parseFaultFromCan(VehicleFaultService.java:95) - longitude: 120.0, latitude: 30.0
懒惰模式： ^(.)+? - 匹配到"[09:18:27:183] [INFO] - "
贪婪模式：^(.)+ - 匹配到"[09:18:27:183] [INFO] - com.leapmotor.emqservice.service.impl.VehicleFaultService.parseFaultFromCan(VehicleFaultService.java:95) - "

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

	a. boost::asio::deadline_timer
	
	void heart_beat_timeout_handler(const boost::system::error_code& error);
	调用timer.async_wait(heart_beat_timeout_handler)后，不管超时或取消或重新定时，回调函数heart_beat_timeout_handler都会被调用。若超时则error为空，若取消或重新定时error为boost::asio::error::operation_aborted
	cancel和expires_from_now返回值都代表被取消的定时任务个数

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
	a. 
	ifstream ifs("123.log");
	while(!ifs.eof()) {
		char buf[128] = {0};
		ifs.read(buf, 10);
		cout << "read " << ifs.gcount() << " bytes: " << buf << endl;
	}
	ifs.clear();
	ifs.seekg(ios::beg);	// 重置指针到最前
	ifs.close();

	b.
	char buf[128];
	ifstream ifs("/mnt/hgfs/ShareFolder/tmp/record.pcms", std::ofstream::in | std::ofstream::binary);
	if (!ifs) {	// file not existing
		cout << "open fail\n";
		return 0;
	}
	
	if (ifs.is_open()) { // ifs is already opened
		cout << "opened\n";
	} else {
		cout << "not open\n";
		ifs.open("/mnt/hgfs/ShareFolder/tmp/record.pcm", std::ofstream::in | std::ofstream::binary);
	}
	ifs.close();
	
	c.
	ifstream ifs; // at this time, ifs is not null & is not opened

	
9. time string
#define TIMEFORMAT "%Y-%m-%d %H:%M:%S"
string time_str(const time_t& time) {
    struct tm* timeTM;
    char strTime[22] = {0};

    timeTM = localtime(&time);
    strftime(strTime, sizeof (strTime) - 1, TIMEFORMAT, timeTM);
    return string(strTime);
}

string now_str() {
    return time_str(time(NULL));
}
#define throw_err(_class_name, _err_msg) throw std::runtime_error(string(_class_name) + "::" + __func__ + ": " + _err_msg)
time_t str_2_time(const char* format, const char* src) {
    if (!format || !src) return -1;
    istringstream ss(src);
    tm TM;
    ss >> get_time(&TM, format);
    if (!ss.fail()) {
        time_t r = mktime(&TM);
        if (r >= 0) return r;
    }
    throw_err("", string("transfer fail, format: ") + format + ", src: " + src);
}

获取毫秒数：
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <sys/timeb.h>
using namespace std;

int main() {
	// c11
    auto time_now = chrono::system_clock::now();
    auto duration_now = time_now.time_since_epoch();
    int millsec = chrono::duration_cast<chrono::milliseconds>(duration_now).count()
            - chrono::duration_cast<chrono::seconds>(duration_now).count() * 1000;
    
	// Linux
    struct timeval tv;
    gettimeofday(&tv, NULL); //该函数在sys/time.h头文件中
    __suseconds_t millsec_1 = tv.tv_usec;

	// Linux
    struct timeb stTimeb;
    ftime(&stTimeb);
    unsigned short int millsec_2 = stTimeb.millitm;

    return 0;
}



10. shared_ptr
	定义后没有用make_shared或new构造，共享指针对象为空 且 use_count() == 0
	用make_shared或new构造后，共享指针对象非空。
	调用reset()或置空(=nullptr)后共享指针对象为空 且 use_count() == 0
	
	共享指针也是一种类，所以直接返回共享指针，相当于调用共享指针复制构造，接收返回值的共享指针变量变化不会影响原来的共享指针变量，如
	shared_ptr<A> a_sptr;
    auto pa = a_sptr;
    pa = make_shared<A>(1);
	此时a_sptr仍为nullptr
	若想共用同一个共享指针，则应返回共享指针引用类型，如
	shared_ptr<A> a_sptr;
    auto& pa = a_sptr;
    pa = make_shared<A>(1);
	此时a_sptr也指向pa构造出来的对象。
	

11. runtime_error
throw std::runtime_error("device::" + std::string(__func__) + ": callback not set");