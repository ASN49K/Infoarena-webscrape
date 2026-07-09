#include<iostream>
#include<fstream>

using namespace std;
const int MAX = 250;

#define MAXIM(a,b)((a > b) ? a : b)



void main(void)
{
	ifstream fin("cmlsc.in", ios::in);
	ofstream fout("cmlsc.out", ios::out);

	int v1[MAX];
	int v2[MAX];
	int v3[MAX][MAX];
	int sir[MAX];
	int n, m, b=0 ,i,j;
	//TREBUIE IN IN NUMARUL DE ELEMENTE ALE VECT
	//A DOUA LINIE SUNT ELEMENT VECT
	//IESIRE PRIMA LIN NR DE ELEMENTE COMUNE IN A SI B
	//A DOUA LINIE ELEMENTELE COMUNE
	fin >> n;
	fin >> m;
	for (int i = 0; i < n ; i++)
	{
		fin >> v1[i];
	}
	for (int i = 0; i < m; i++)
	{
		fin >> v2[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v1[i] == v2[j])
			{
				b++;
			}

		}
	}

	fout << b << endl;



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v1[i] == v2[j])
			{
				v3[i][j] = v1[i];
				fout << v3[i][j]<<" ";
			}
				
		}
	} 


	




	fin.close();
	fout.close();
}