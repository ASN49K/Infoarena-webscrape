//
//  main.cpp
//  LCS
//
//  Created by Casuneanu Andrei on 22/01/14.
//  Copyright (c) 2014 Casuneanu Andrei. All rights reserved.
//

#include <fstream>
#define NMAX 1100
#define IN "cmlsc.in"
#define OUT "cmlsc.out"
using namespace std;

ifstream fin(IN);
ofstream fout(OUT);

int n, m;
int a[NMAX], b[NMAX];
int LCS[NMAX][NMAX];

void citire();
void showtime();
void afisare();


int main(int argc, const char * argv[])
{
	citire();
	showtime();
	afisare();
    return 0;
}

void afisare()
{
	fout <<LCS[1][1]<<'\n';
	
	//reconstituirea
	int i=1, j=1;
	while (i<=n && j<=m)
		if (a[i]==b[j]) {fout <<a[i]<<' '; i++; j++;}
		else if (LCS[i][j]==LCS[i+1][j]) i++;
			else j++;
	fout <<'\n';
	fout.close();
}

void showtime()
{
	int i ,j;
	for (i=n; i>0; i--)
		for (j=m; j>0; j--)
			if (a[i]==b[j])
				LCS[i][j]=1+LCS[i+1][j+1];
			else
			if (LCS[i][j+1]>LCS[i+1][j])
				LCS[i][j]=LCS[i][j+1];
			else
				LCS[i][j]=LCS[i+1][j];
}

void citire()
{
	fin >>n>>m;
	
	int i;
	for (i=1; i<=n; i++) fin >>a[i];
	for (i=1; i<=m; i++) fin >>b[i];
}