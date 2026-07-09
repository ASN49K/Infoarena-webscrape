#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
    int t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        fin>>a>>b;
        while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    fout<<a<<endl;
    }
}