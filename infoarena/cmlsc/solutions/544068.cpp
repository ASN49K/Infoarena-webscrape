#include <iostream>
#include <fstream>
#define MAX 1024

using namespace std;
int M , N , a[MAX], b[MAX], d[MAX][MAX],sir[MAX];

int main(){
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	in >> M >> N;
	for( int i = 1 ; i <= M ; i++)
		in >> a[i];

	for( int i = 1 ; i <= N ; i++)
		in >> b[i];
	
	for(int i =1 , j; i <= M ;i++)
		for( j = 1 ; j <= N ; j++)
			if( a[i] == b[j] ) 
			{
							d[i][j] = d[i-1][j-1] + 1;
			}
			else
			{
					d[i][j] = max (d[i-1][j], d[i][j-1]);
			}
	int lung = 0;
	for( int i = M, j = N ; i ; )
		if( a[i] == b[j] ) 
		{
			sir[ lung ++] = a[i];
			i-- ; j--;
		}
		else 
					if (d[i-1][j] < d[i][j-1] ) 
						j--;
					else
						i--;
		
	
	out << lung<<endl;
	for( int i = lung-1  ; i>= 0 ; i--)
		out<<sir[i] << " " ;
	out.close();

}
