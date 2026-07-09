#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define NMAX 10009
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
///iau a.i sa egalez pietrele 
///determin daca primul are str de castig pt n=2
//!!! acum pt n mai mare 
//
ll n;
ll v[NMAX];
ll x;
ll i;
ll j;
int main()
{
	ll t;
	fin >> t;
	while (t--)
	{
		fin >> n;
		x = 0;
		for (i = 1; i <= n; i++)
		{
			fin >> v[i];
			x = x ^ v[i];
		}
		//cand mut voi schimba cel putin un bit o sa scad macar un bit
		///matricea repre in baza 2
		// imi aleg un nr suf de mare si schimb bitii cu cei care sunt 1 in suma xor
		//pot inversa mereu?
		//aparent da
		///caut un numar care sa>= cea mai mare putere 
		///y= valoarea 
		/// scad din y- x XOR y
		///inversez bitii
		if (x == 0)
			fout << "NU\n";
		else
			fout << "DA\n";
	}


	return 0;
}