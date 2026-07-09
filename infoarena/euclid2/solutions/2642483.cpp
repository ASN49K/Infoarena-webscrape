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
int cmmdc2(int a, int b)
{
    if(a<b) return cmmdc2(b,a);
    if (b==0) return a;
    return cmmdc2(b,a-b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t;
    fin>>t;
    for(int i=0; i<t; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
}
