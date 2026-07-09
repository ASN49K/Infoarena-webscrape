#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t,c,i;
    fin>>t;
    for(i = 0; i < t; ++i)
    {
        fin>>a>>b;
        while(b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        fout<<a;
        fout<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
