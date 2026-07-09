#include <fstream>
#include <vector>
#include <set>
using namespace std;

int a[1024];
int b[1024];
int contorA[256], contorB[256];
int k, numere[1024], contorNumere;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int main()
{
	int n, m, x;


	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		contorA[a[i]]++;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		contorB[b[i]]++;
	}

	if (n > m)
	{

		for (int i = 0; i < n; i++)
		{
			if (contorA[a[i]] != 0 && contorB[a[i]] != 0)
			{
				if (contorA[a[i]] < contorB[a[i]])
				{
					for (int j = 0; j < contorA[a[i]]; j++)
					{
						numere[contorNumere] = a[i];
						contorNumere++;
					}
				}
				else
				{
					for (int j = 0; j < contorB[a[i]]; j++)
					{

						numere[contorNumere] = a[i];
						contorNumere++;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (contorA[b[i]] != 0 && contorB[b[i]] != 0)
			{
				if (contorA[b[i]] < contorB[b[i]])
				{
					for (int j = 0; j < contorA[b[i]]; j++)
					{
						numere[contorNumere] = b[i];
						contorNumere++;
					}
				}
				else
				{
					for (int j = 0; j < contorB[b[i]]; j++)
					{

						numere[contorNumere] = b[i];
						contorNumere++;
					}
				}
			}
		}
	}

	cout << contorNumere << "\n";

	for (int i = 0; i < contorNumere; i++)
	{
		cout << numere[i] << " ";
	}


}

