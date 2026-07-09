#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin ("nim.in" );
ofstream fout("nim.out");
#define baza 1
#define MAX 2000004
#define MOD 9973
typedef long long int lli;


int n,t,s,i,g;

int main()
{
    fin>>t;

    for(int ki=1;ki<=t;ki++)
    {
        fin>>n;
        fin>>s;
        for(i=1;i<n;i++)
        {
            fin>>g;
            s^=g;
        }
        if(s)
            fout<<"DA";
        else
            fout<<"NU";
        fout<<"\n";
    }

    return 0;
}
