#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
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
    int term1,term2,no;
    fin>>no;
    for(int i=0;i<no;i++)
    {
    fin>>term1;
    fin>>term2;
    fout<<cmmdc(term1,term2)<<endl;
    }
}
