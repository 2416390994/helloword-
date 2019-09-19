#include<stdio.h>
#include<stdlib.h>
void f(int*&p){
    printf("\n%x", &p);
    printf("\n%x", p);
     printf("\n%x\n", *p);
 * p = 0xff;
}
 void main()
 {
	     int a = 0x10;
	     printf("\n%x", &a);
	     printf("\n%x\n", a);
	     int *b = &a;
	     printf("\n%x", &b);
	     printf("\n%x", b);
	     printf("\n%x\n", *b);
	     f(b);
	     printf("\n%x\n", a);
	 }

//#include<stdio.h>
//#include<stdlib.h>
// void f(int**p){
//	 printf("\n%x", *p);
//	 printf("\n%x", p);
//	 printf("\n%x\n", **p);
//	 **p = 0xff;
// }
// void main()
// {
//	 int a = 0x10;
//	 printf("\n%x", &a);
//	 printf("\n%x\n", a);
//	 int *b = &a;
//	 printf("\n%x", &b);
//	 printf("\n%x", b);
//	 printf("\n%x\n", *b);
//	 f(&b);
//	 printf("\n%x\n", a);
// }