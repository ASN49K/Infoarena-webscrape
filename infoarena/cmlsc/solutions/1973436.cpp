//============================================================================
// Name        : Subsit.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

#define maxim(a,b) ((a>b)?a:b)
#define IN  "cmlsc.in"
#define OUT "cmlsc.out"
#define LMax 1025

using namespace std;

ifstream in(IN);
ofstream out(OUT);

int a[LMax] , b[LMax] , d[LMax][LMax] , sol[LMax] ,  N , M , dist = 0 ;

void outs()
{
    int i ;
    out << --dist << '\n' ;
    for(i=dist;i>=1;i--)
    	out << sol[i] << " " ;
}

void reface()
{
	int i , j ;
	i = N ; j = M ;
	while(i>0&&j>0)
	{
		if(a[i]==a[j]) {
			sol[++dist] = a[i] ;
			i--;j--;
		}
		else if(d[i-1][j] > d[i][j-1])
			i--;
		else j--;
	}
	outs();
}
void rezolva()
{
	int i , j ;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(a[i]==b[j])
				d[i][j] = 1 + d[i-1][j-1] ;
			else
				d[i][j] = maxim(d[i-1][j],d[i][j-1]);
	reface();
}


void citeste()
{
	in >> N >> M ;
	int i ;
	for(i=1;i<=N;i++)
		in >> a[i] ;
	for(i=1;i<=M;i++)
		in >> b[i] ;
	rezolva();
}

int main() {
   citeste();
}
