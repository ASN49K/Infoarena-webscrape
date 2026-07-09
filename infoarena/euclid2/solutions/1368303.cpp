#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b,r,T,i;

int cmmdc(int a, int b)
{
    do {
        r = a % b;
        a = b;
        b = r;
    } while(r != 0);
    return a;
}

int main()
{
    fin>>T;
    for(i=0; i<T; i++)
    {
        fin>>a>>b;
            fout<<cmmdc(a,b)<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}

