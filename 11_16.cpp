//#include<iostream>
//#include<vector>
//using namespace std;
//int addAB(int A, int B) {
//	if (A == 0)
//	{
//		return B;
//	}
//	if (B == 0)
//	{
//		return A;
//	}
//	int c = A ^ B;
//	int d = (A & B) << 1;
//	return addAB(c, d);
//}
//int main()
//{
//	int c = addAB(10, 10);
//	cout << c << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		//b������ݹ�
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		// a�������ֹ����
		return n + m;
	else
		//����Ϊ0ʱ�� ·��Ϊ0
		return 0;
}
int main()
{
	cout << pathNum(4, 3);
	/*int a;
	int b;
	cin >> a;
	cin >> b;
	cout << ((a - 1)*b) + ((b - 1) * a) + 2;
	return 0;*/
	

}