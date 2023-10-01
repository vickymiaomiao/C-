#define _CRT_SECURE_NO_WARNINGS 1   
#include <iostream>
#include <string>
using namespace std;

/*
* �����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
*����ʱ��װ��̨��ͬ�Ľ��й���
*/
//����ͬ�������
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
//������
class Computer
{
public:
	//���캯���д������������ָ��
	Computer(Cpu* cpu, VideoCard* vc,Memory *mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���������ÿ����������Ľӿ�,�ú�����������
	void work()
	{
		m_cpu->caculate();
		m_vc->diaplay();
		m_mem->storage();
	}

	//�ṩ�����������ͷ�3�����Ե����
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
	Cpu* m_cpu;  // cpuָ��
	VideoCard* m_vc;
	Memory* m_mem;
};

//������������ intel
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

//lenovo���볧��
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

//��ʼ��װ��ͬ�ĵ���
void test01()
{
	//��װ��һ̨�������
	Cpu* intelcpu = new IntelCpu;
	VideoCard* intelcard = new IntelVideoCard;
	Memory* intelmemory = new IntelMemory;
	Computer *c1=new Computer(intelcpu, intelcard, intelmemory);
	c1->work();
	delete c1;   //�ͷŵ������ĵ�������
	cout << "--------------------" << endl;
	//��װ�ڶ�̨
	Computer* c2 = new Computer(new LenovoCpu,new LenovoVideoCard,new LenovoMemory);
	c2->work();
	delete c2;   //�ͷŵ������ĵ�������
	cout << "--------------------" << endl;
	//��װ����̨
	Computer* c3 = new Computer(new LenovoCpu, new IntelVideoCard, new LenovoMemory);
	c3->work();
	delete c3;   //�ͷŵ������ĵ�������
}


int main()
{
	test01();
	return 0;
}