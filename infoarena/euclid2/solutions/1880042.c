#include <stdio.h>
#include<conio.h>
int cmmdc(int a, int b)
{
    int r;
    if((a == 0) || (b == 0))
        return 0;
    else if((a < 0) || (b < 0))
        return -1;

    do
    {
        r = a % b;
        if(r==0)
            break;
        a = b;
        b = r;
    }
    while(true);

    return b;
}
int main(void)
{
	int num1,num2;
	printf("num1= ");
	scanf("%d",&num1);
	printf("num2= ");
	scanf("%d",&num2);
	printf("%d",cmmdc(num1,num2));
}

