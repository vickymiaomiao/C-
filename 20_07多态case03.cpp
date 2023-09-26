#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
*测试时组装三台不同的进行工作
*/
//抽象不同的零件类
class Cpu
{
public:
	virtual void caculate() = 0;
};

class VideoCard
{
public:
	virtual void diaplay() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};
//电脑类
class Computer
{
public:
	//构造函数中传入三个零件的指针
	Computer(Cpu* cpu, VideoCard* vc,Memory *mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数，调用每个零件工作的接口,让函数工作起来
	void work()
	{
		m_cpu->caculate();
		m_vc->diaplay();
		m_mem->storage();
	}

	//提供析构函数来释放3个电脑的零件
	~Computer()
	{
		if(m_cpu!=NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	Cpu* m_cpu;  // cpu指针
	VideoCard* m_vc;
	Memory* m_mem;
};

//具体的零件厂商 intel
class IntelCpu :public Cpu
{
public:
	void caculate()
	{
		cout << "intel cpu" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	void diaplay()
	{
		cout << "intel videocard" << endl;
	}
};
class IntelMemory :public Memory 
{
public:
	void storage()
	{
		cout << "intel memory" << endl;
	}
};

//lenovo联想厂商
class LenovoCpu :public Cpu
{
public:
	void caculate()
	{
		cout << "Lenovo cpu" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	void diaplay()
	{
		cout << "Lenovo videocard" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo memory" << endl;
	}
};

//开始组装不同的电脑
void test01()
{
	//组装第一台电脑零件
	Cpu* intelcpu = new IntelCpu;
	VideoCard* intelcard = new IntelVideoCard;
	Memory* intelmemory = new IntelMemory;
	Computer *c1=new Computer(intelcpu, intelcard, intelmemory);
	c1->work();
	delete c1;   //释放掉堆区的电脑数据
	cout << "--------------------" << endl;
	//组装第二台
	Computer* c2 = new Computer(new LenovoCpu,new LenovoVideoCard,new LenovoMemory);
	c2->work();
	delete c2;   //释放掉堆区的电脑数据
	cout << "--------------------" << endl;
	//组装第三台
	Computer* c3 = new Computer(new LenovoCpu, new IntelVideoCard, new LenovoMemory);
	c3->work();
	delete c3;   //释放掉堆区的电脑数据
}


int main()
{
	test01();
	return 0;
}