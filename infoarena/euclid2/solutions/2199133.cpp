#define FILE_INPUT

#ifdef FILE_INPUT
#include <fstream>
#else
#include <iostream>
#endif

using namespace std;

//int euclid(int a, int b)
//{
//	if (a < b)
//	{
//		a ^= b;
//		b ^= a;
//		a ^= b;
//	}
//
//	// a o sa fie ala mai mare
//
//	while (b != 1 && a % b != 0)
//	{
//		a %= b;
//		a ^= b;
//		b ^= a;
//		a ^= b;
//	}
//
//	return b;
//}

int euclid(int a, int b)
{
	if (a % b == 0)
		return b;
	return euclid(b, a % b);
}

int main()
{
	int n;

#ifdef FILE_INPUT == 1
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in >> n;
#else
	cin >> n;
#endif 

	for (int i = 0; i < n; i++)
	{
		int a, b;
#ifdef FILE_INPUT
		in >> a >> b;

		if (a < b)
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}

		out << euclid(a, b) << endl;
#else
		cin >> a >> b;

		if (a < b)
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}

		cout << euclid(a, b) << endl;
#endif
	}

	return 0;
}