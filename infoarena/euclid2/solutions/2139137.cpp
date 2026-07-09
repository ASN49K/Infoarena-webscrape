#include <iostream>

int SimpleCmmdc(int a, int b)
{
	int min = 0xFFFFFF;

	if (a < b)
		min = a;
	else
		min = b;

	for (int i = min; i >= 1; i--)
	{
		if (a%i == 0 && b%i == 0)
			return i;
	}
}

void main()
{
	int a, b;
	printf("Enter a: \n");
	scanf("%d", &a);
	printf("Enter b: \n");
	scanf("%d", &b);

	printf("Cmmdc: %d\n", SimpleCmmdc(a, b));

	system("pause");
}