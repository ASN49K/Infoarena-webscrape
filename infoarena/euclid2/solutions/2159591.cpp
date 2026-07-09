#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int euclid(int x,int y)
{
    if(!y) return x;
    euclid(y,x%y);
}
int main()
{
    fin>>n;
    int k1,k2;
    for(int i=0;i<n;i++)
    {
        fin>>k1>>k2;
        fout<<euclid(k1,k2)<<"\n";
    }
}
