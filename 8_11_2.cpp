#include <iostream>
using namespace std;
extern const int a = 10;
extern int b = 20;
int main()
{
	printf("%d", a);
	printf("%d", b);
	return 0;
}