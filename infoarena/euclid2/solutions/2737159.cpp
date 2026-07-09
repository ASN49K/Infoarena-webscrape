#include <iostream>
#include <fstream>
using namespace std;
int nr_numere,nr_a,nr_b,nr_t;
int aflare(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    else
    {
        aflare(b%a,a);
    }
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>nr_t;
    for(int i=0;i<nr_t;i++)
    {
        fin>>nr_a>>nr_b;
        fout<<aflare(nr_a,nr_b)<<'\n';
    }
}