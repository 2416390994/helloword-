//#include<iostream>
//#include<queue>
//using namespace std;
//class A
//{
//public:
//	static A* get()
//	{
//		if (a == nullptr)
//			func();
//		return a;
//	}	
//private:
//	static void func()
//	{
//		cout << 111111 << endl;
//		a = new A;
//	}
//	A(){}
//	A(const A& a) = delete;
//	A operator=(const A& a) = delete;
//	static A* a;
//};
//A* A::a = nullptr;
//
//
//
//
//
//
//
//class C
//{
//
//
//};
//
//int main()
//{
//	A* p = A::get();
//	C c;
//	A* s = A::get();
//	A* s1 = A::get();
//	return 0;
//}

//��װtcpsocket�࣬�����ṩ�������Ľӿ�
//1.�����׽���
//2.�󶨵�ַ��Ϣ
//3.����˿�ʼ�������ͻ��������˷�������
//4.����˻�ȥ�����i���ҵĿͻ����µ�socket
//5.��������
//6.��������
//7.�ر��׽���
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<error.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define CHECK(p) if((p) == false){return -1;}
using namespace std;
class Tcpsocket
{
public:
	Tcpsocket()
	{}
	~Tcpsocket()
	{}
	bool Socket()
	{
		_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (_sockfd < 0)
		{
			perror("socket error\n");
			return false;
		}
		return true;
	}
	bool Bind(string &ip, uint16_t port)
	{
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = bind(_sockfd, (sockaddr*)&addr, len);
		if (ret < 0)
		{
			perror("bind error\n");
			return false;
		}
		return true;
	}
	bool Listen(int backlog = 5)
	{
		//int listen(int socket, int backlog);
		//socket:�׽���������
		//backlog:��󲢷��������������ں�����������Ӷ��нڵ�ĸ���
		//backlog�������Ĳ��Ƿ�����ܽ��ܵĿͻ���������ޣ�����ͬһʱ�����Ľ��ܵ����ޣ�������ͬһʱ�䴴������С�Һ����Ӵ�����
		int ret = listen(_sockfd, backlog);
		if (ret < 0)
		{
			perror("listen error\n");
			return false;
		}
		return true;
	}
	bool Accept(Tcpsocket &cli, string &cliip, uint16_t cliport)
	{
		//int accept(int s, struct sockaddr *addr,socklen_t *addrlen);
		//s:�׽���������
		//addr: �������ӵĿͻ��˵�ַ��Ϣ����
		//addrlen:�½��ͻ��˵ĵ�ַ��Ϣ����
		struct sockaddr_in addr;
		socklen_t len = sizeof(addr);
		int sockfd = accept(_sockfd, (struct sockaddr*) &addr, &len);
		if (sockfd < 0)
		{
			perror("accept error\n");
			return false;
		}
		cli.SetFd(sockfd);
		cliip = inet_ntoa(addr.sin_addr);
		cliport = ntohs(addr.sin_port);
		return true;
	}
	void SetFd(int sockfd)
	{
		_sockfd = sockfd;
	}
	bool Connect(string &srv_ip, uint16_t srv_port)
	{
		//int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
		//socket: �ͻ����Ǳ������������׽���������
		//addr: ����˵ĵ�ַ��Ϣ
		//addrlen: ����˵�ַ��Ϣ����
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(srv_port);
		addr.sin_addr.s_addr = inet_addr(srv_ip.c_str());
		socklen_t len = sizeof(addr);
		int ret = connect(_sockfd, (struct sockaddr*)&addr, len);
		if (ret < 0)
		{
			perror("connect error\n");
			return false;
		}
		return true;
	}
	bool Recv(string &buf)
	{
		//ssize_t recv(int sockfd, void *buf, size_t len, int flags);
		//socket:�����Ϊ�ͻ����½���socket������
		//flags: 0 Ĭ���������ܣ�û�����ݾ�һֱ�ȴ�
		//		MSG_PEEK�������ݣ��������ݲ����ӽ��ջ������Ƴ�������̽���Խ��ܣ���Ϊtcp��Ե�����ʽ���ݣ����ܻ���ܵĲ�����һ�����������ݣ�������Ҫ̽���ԵĽ��ܣ�̽�������Ƿ�����
		//����ֵ��ʵ�ʽ��ܵ��ֽڳ��ȣ�������-1�������ӶϿ��򷵻�0
		//recvĬ���������ģ���ζ��û��������һֱ�ȣ����᷵��0������0ֻ��һ��������Ǿ������ӶϿ������ټ���ͨ��
		char tmp[4096] = { 0 };//������Բ�Ҫ���tmp��ֱ��ʹ��bufӦ��Ҳ���԰ɣ�
		int ret = recv(_sockfd, tmp, 4096, 0);
		if (ret < 0)
		{
			perror("recv error");
			return false;
		}
		else if (ret == 0)
		{
			perror("peer shutdown");
			return true;
		}
		buf.assign(tmp, ret);//�ѻ�������ʵ�ʽ��յ��ĳ������ݷŵ�buf�д���ȥ
		return true;
	}
	bool Send(string &buf)
	{
		// int send(int s, const void *msg, size_t len, int flags);
		int ret = (_sockfd, buf.c_str(), buf.size(), 0);
		if (ret < 0)
		{
			perror("error send");//�����쳣
			return false;
		}
		return true;
	}
	bool Close()
	{
		close(_sockfd);
		return true;
	}
private:
	int _sockfd;
};