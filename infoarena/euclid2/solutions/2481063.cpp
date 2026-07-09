
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b,T,i,c;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(i=1; i<=T; i++)
        while(fin>>a>>b)
        {
            while (b)
            {
                c = a % b;
                a = b;
                b = c;
            }
            fout<<a<<'\n';
        }

    return 0;
}
