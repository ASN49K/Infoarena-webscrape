#include <iostream>
#include <fstream>

using namespace std;

int M, N, sir1[1025], sir2[1025], MAX = 0, ssCom[1025], dMat[1025][1025];

void CitireDateIntrare();
void AfisareRezultat();
int Maxim(int a, int b);
void LungimeSubsirComun();
void AfisareSubsirComun();

int main()
{
	CitireDateIntrare();
	LungimeSubsirComun();
	AfisareSubsirComun();
	AfisareRezultat();
}

void CitireDateIntrare()
{
	ifstream fIn("cmlsc.in");
	fIn >> M >> N;
	for (int i = 1; i <= M; i++)
		fIn >> sir1[i];
	for (int i = 1; i <= N; i++)
		fIn >> sir2[i];
	fIn.close();
}

void AfisareRezultat()
{
	ofstream fOut("cmlsc.out");
	fOut << MAX << endl;
	for (int i = MAX; i >= 1; i--)
		fOut << ssCom[i] << ' ';
	fOut.close();
}

int Maxim(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void LungimeSubsirComun()
{
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			if (sir1[i] == sir2[j])
				dMat[i][j] = dMat[i - 1][j - 1] + 1;
			else
				dMat[i][j] = Maxim(dMat[i][j - 1], dMat[i - 1][j]);
}

void AfisareSubsirComun()
{
	int i = M, j = N;
	while (i >= 1 && j >= 1)
	{
		if (sir1[i] == sir2[j])
		{
			MAX++;
			ssCom[MAX] = sir1[i];
			i--;
			j--;
		}
		else
			if (dMat[i][j - 1] > dMat[i - 1][j])
				j--;
			else
				i--;
	}
}
