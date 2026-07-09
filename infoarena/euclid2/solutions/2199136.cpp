#define FILE_INPUT

#ifdef FILE_INPUT
#include <cstdio>
#else
#include <iostream>
#endif

using namespace std;

int euclid(int a, int b)
{
	if (a < b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}

	// a o sa fie ala mai mare

	while (b != 1 && a % b != 0)
	{
		a %= b;
		a ^= b;
		b ^= a;
		a ^= b;
	}

	return b;
}

//int euclid(int a, int b)
//{
//	if (a % b == 0)
//		return b;
//	return euclid(b, a % b);
//}

int main()
{
	int n;

#ifdef FILE_INPUT
	/*ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in >> n;*/
	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid2.out", "w");
	fscanf(in, "%d", &n);
#else
	cin >> n;
#endif 

	for (int i = 0; i < n; i++)
	{
		int a, b;
#ifdef FILE_INPUT
		//in >> a >> b;

		//out << euclid(a, b) << endl;

		fscanf(in, "%d", &a); fscanf(in, "%d", &b);
		fprintf(out, "%d\n", euclid(a, b));
#else
		cin >> a >> b;
		cout << euclid(a, b) << endl;
#endif
	}

	return 0;
}