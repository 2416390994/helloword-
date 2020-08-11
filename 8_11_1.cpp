#include <iostream>
using namespace std;

extern const int a;
extern int b;

void func()
{
	printf("%d", a);
	printf("%d", b);
}