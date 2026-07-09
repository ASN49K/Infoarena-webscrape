#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}

int main()
{
    int N;
    int nr1;
    int nr2;
    fin>>N;
    while(N!=0)
    {
        fin>>nr1;
        fin>>nr2;
        fout<<cmmdc(nr1,nr2)<<"\n";
        N--;
    }
    return 0;
}
