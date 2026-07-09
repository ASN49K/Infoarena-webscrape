#include <iostream>
#include <fstream>
using namespace std;
int cmmdc ( int , int );

int main()
{
    ifstream fin ( "euclid2.in");
    ofstream fout ( "euclid2.out");
    int n,a,b,i;

    fin>>n;
    for (i=0;i<n;i++)
    {
        fin>>a>>b;

        fout<<cmmdc(a,b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}

int cmmdc ( int a , int b )
{
    int r;
    while ( b!=0 )
        {
            r=a%b;
            a=b;
            b=r;
        }
    return a;

}
