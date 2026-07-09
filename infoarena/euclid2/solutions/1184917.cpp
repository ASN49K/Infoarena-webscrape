#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,r,T;
    fin>>T;
    for(int i=0;i<T;i++)
    {
        fin>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<endl;
    }


    return 0;
}
