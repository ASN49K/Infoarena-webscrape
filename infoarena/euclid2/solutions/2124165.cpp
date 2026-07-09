#include<iostream>
#include<fstream>
using namespace std;
int a,b,n;
int main()
{
    ofstream fout("euclid2.out");
    ifstream fin("euclid2.in");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
    fin>>a>>b;
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    fout<<a<<"\n";
    }
}
