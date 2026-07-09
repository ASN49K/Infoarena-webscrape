#include<iostream>
#include<fstream>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while (b!=0)
        {
        c=a%b;
        a=b;
        b=c;
        }
    return a;
}
int main()
{
    int i,j,T,k;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>j>>k;
        fout<<euclid(j,k)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
