#include<iostream>
using namespace std;
int euclid(int a, int b)
{
	int r;
	while (b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	int n,a,b;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a >> b;
		std::cout << euclid(a, b) << endl;
	}
	system("pause");
	return 0;
}