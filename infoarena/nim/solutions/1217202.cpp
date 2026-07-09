#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t;
long long a,b;


int main()
{
    fin>>t;
    for (int i=0; i<t; i++)
    {
        int n;
        fin>>n;
        int rez=0;
        for (int j=0; j<n; j++)
        {int x; fin>>x; rez = rez^x;}
        if (!rez) fout<<"NU";
        else fout<<"DA";
        fout<<'\n';
    }

    return 0;
}
