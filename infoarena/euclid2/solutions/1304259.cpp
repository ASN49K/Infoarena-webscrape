#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int x,y,i;
long n;
int euclid ( int, int ) ;


int main()
{
	fin >> n ;
	for ( i = 1 ; i <= n ; i++ )
	{
		fin >> x >> y ;
		fout << euclid ( x, y ) << '\n' ;
	}
	return 0 ;
}

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

/*

	int cmmdc (int a, int b)
	{
		while (a != b)
			if (a > b)
				a = a - b;
			else
				b = b - a;
		return a;
	} 





*/
