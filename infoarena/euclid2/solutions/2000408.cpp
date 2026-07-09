#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(0==b) return a;
    else return cmmdc(b, a%b);
}

main()
{
    int x, y, n;
    fin>>n;
    while(n!=0)
    {
        fin>>x>>y;
		if(x<y){
			int aux = x;
			x=y; y=aux;
		}
        fout<<cmmdc(x, y)<<endl;
        n--;
    }
}
