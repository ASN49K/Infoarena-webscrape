#define IOSTREAM 0

#if IOSTREAM
#include <iostream>
#else
#include <fstream>
#endif

int main()
{
	int n; 
#if IOSTREAM
	std::cin >> n;
#else
	std::ifstream in("euclid2.in");
	in >> n;
#endif

	for (int i = 0; i < n; i++)
	{
		int a, b;
#if IOSTREAM
		std::cin >> a >> b;
#else
		in >> a >> b;
#endif

		while (a % b != 0)
		{
			int temp = a % b;
			a = b;
			b = temp;
		}
#if IOSTREAM
		std::cout << b << std::endl;
#else
		std::ofstream out("euclid2.out");
		out << b << std::endl;
#endif
	}

#if IOSTREAM
	system("pause");
#endif

	return 0;
}