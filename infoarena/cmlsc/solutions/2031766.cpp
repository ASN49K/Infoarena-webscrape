#include<iostream>;
#include<fstream>;
#include<algorithm>;
using namespace std;
int func1(int i, int j, int a[], int b[], int m, int n, int index);

int numbers[1025];


int main()
{
	ifstream in;
	ofstream out;
	in.open("cmlsc.in");
	out.open("cmlsc.out");

	int m, n, a[1025], b[1025], i, t = 0;
	in >> m >> n;
	for (i = 1; i <= m; i++)
		in >> a[i];
	for (i = 1; i <= n; i++)
		in >> b[i];

	t = func1(1, 1, a, b, m, n, 1);
	out << t << endl;

	for (i = 1; i <= 1024; i++)
		if(numbers[i] > 0)
			out << numbers[i] << " ";

	return 0;
}

int func1(int i, int j, int a[], int b[], int m, int n, int index)
{
	if (i > m || j > n)
	{
		return 0;
	}

	if (a[i] == b[j])
	{
		numbers[index] = a[i];
		return func1(i + 1, j + 1, a, b, m, n, index+1) + 1;	
	}

	if (a[i] != b[j])
	{
		return max(func1(i + 1, j, a, b, m, n, index), func1(i, j + 1, a, b, m, n, index));
	}
}