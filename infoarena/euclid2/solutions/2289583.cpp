#include<iostream>
#include<fstream>
using namespace std;
long cmmdc(long a, long b)
{
    long r;
    while(b)
    {
        r = b % a;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long term1,term2,no;
    fin>>no;
    for(long i=0;i<no;i++)
    {
    fin>>term1;
    fin>>term2;
    fout<<cmmdc(term1,term2)<<"\n";
    }
}
