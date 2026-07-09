#include<iostream>
#include<fstream>

using namespace std;


void main()
{
	ifstream fin("euclid2.in", ios::in);
	ofstream fout("euclid2.out", ios::out);
	//avem un int de nr perechi
	int p = 0,nr1,nr2;
	fin >> p;
	//avem cate 2 numere pentru fiecare pereche;

	for (int i = 0; i < p; i++)
	{
		int j;
		fin >> nr1;
		fin >> nr2;
		while (nr2 > 0){
		    j = nr1 % nr2;	 // 12 /9 = 1 rest 3 => 12 = 9 (nr1 = 9 si nr 2 la fel) nr2  = r = 3  => nr1 = 9 nr2 = 3 => 3
			nr1 = nr2;
			nr2 = j;
		}
		fout << nr1 << endl;
	}

	fin.close();
	fout.close();
}

