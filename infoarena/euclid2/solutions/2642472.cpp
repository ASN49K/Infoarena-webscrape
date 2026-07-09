#include<fstream>
#include<iostream>

using namespace std;

int cmmdc(int a, int b)
{
    int d=1;
    for(int i=2; i<=a; i++)
    {
        while(a%i==0 && b%i==0)
        {
            a/=i;
            b/=i;
            d*=i;
        }
    }
    return d;

}

int main()
{
    ifstream fin("euclid.in");
    ofstream fout("euclid.out");
    int a,b,t;
    fin>>t;
    for(int i=0; i<t; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
}
