//============================================================================
// Name        : SubsirMaximComun.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

#define lMax 1024

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int l[lMax+1][lMax+1] , m , n , a[lMax+1] , b[lMax+1] ;

void citire()
{
	in >> m >> n ;
	int i ;
	for(i=1;i<=m;i++)
		in >> a[i] ;
	for(i=1;i<=n;i++)
		in >> b[i] ;
}

void bord()
{
	int i ;
	for(i=1;i<=m;i++)
		l[0][i] = 0 ;
	for(i=1;i<=n;i++)
		l[i][0] = 0 ;
}

void afisare()
{
	int i , j ;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
			cout << l[i][j] << " " ;
		cout << '\n' ;
	}
}
int Mah(int a,int b)
{
	if(a>b) return a  ;
	return b;
}
void LSC()
{
	int i , j ;
	bord();
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if( b[j]== a[i] ) l[i][j] = l[i-1][j-1] +1;
			else l[i][j] = Mah(l[i-1][j],l[i][j-1]);
	//afisare();
}

void reface(int x,int y)
{
	if(x>0&&y>0) {
	if(b[y]==a[x]) {reface(x-1,y-1);
	   out << a[x] << " ";
	}
	else if(l[x][y]==l[x-1][y]) reface(x-1,y) ;
	else if(l[x][y]==l[x][y-1]) reface(x,y-1);
	}
}
int main() {
	citire();
	LSC();
	out << l[m][n] << '\n' ;
	reface(m,n);
	return 0;
}
