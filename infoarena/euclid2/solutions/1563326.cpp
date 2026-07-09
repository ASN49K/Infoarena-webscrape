#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a ,b, t;
int euclid(int a , int b)
{
    if(not b)
        return a;
    else
        return euclid(b,a%b);
}

int main()
{
    fin>>t;
    while(t--)
        {fin>>a>>b;
    fout<<euclid(a,b)<<'\n';}
}
