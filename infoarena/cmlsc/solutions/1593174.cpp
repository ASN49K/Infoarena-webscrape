#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdarg>
#define FOR(i,a,b) for (register int i=a;i<=b;i++)
using namespace std;

//freopen("cmlsc.in","r",stdin);
//freopen("cmlsc.out","w",stdout);
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int elemA[1025];
int frecA[257];
int elemB[1025];
int frecB[257];
int joj[1025];
int main()
{
    int loadA;
    int loadB;
    in>>loadA;
    in>>loadB;
    int mini=(loadA>loadB?loadB:loadA);

    for(register int i=0;i<=loadA-1;i++)
    {
        in>>elemA[i];
        frecA[elemA[i]]++;
    }
    for(register int i=0;i<=loadB-1;i++)
    {
        in>>elemB[i];
        frecB[elemB[i]]++;
    }
    int ctr=0;
    int* kek;
    int* frek;
    if(mini==loadA) {kek=elemA; frek=frecB;}
    else {kek=elemB; frek=frecA;}
    for(register int i=0;i<=mini-1;i++)
    {
        if(*(frek+(*(kek+i)))!=0)
        {
            joj[ctr]=*(kek+i);
            ctr++;
        }
    }
    out<<ctr;
    out<<endl;
    for(register int i=0;i<=ctr-1;i++) out<<joj[i]<<" ";
}

