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
int elemB[1025];
int joj[1025];
struct frequency{bool is:1;int pos;};
frequency frecA[257];
frequency frecB[257];
int main()
{
    int loadA;
    int loadB;
    in>>loadA;
    in>>loadB;
    int mini=(loadA>loadB?loadB:loadA);

    for(register int i=0; i<=loadA-1; i++)
    {
        in>>elemA[i];
        frecA[elemA[i]].is=true;
        frecA[elemA[i]].pos=i;
    }
    for(register int i=0; i<=loadB-1; i++)
    {
        in>>elemB[i];
        frecB[elemB[i]].is=true;
        frecB[elemB[i]].pos=i;
    }
    int ctr=0;
    int ret=-1;

    if(mini==loadA)
        for(register int i=0; i<=mini-1; i++)
        {
            if(frecB[elemA[i]].is && ret<frecB[elemA[i]].pos)
            {
                ret=frecB[elemA[i]].pos;
                joj[ctr]=elemA[i];
                ctr++;
            }
        }
    else
        for(register int i=0; i<=mini-1; i++)
        {
            if(frecA[elemB[i]].is && ret<frecA[elemB[i]].pos)
            {
                ret=frecA[elemB[i]].pos;
                joj[ctr]=elemB[i];
                ctr++;
            }
        }
    out<<ctr;
    out<<endl;
    for(register int i=0; i<=ctr-1; i++) out<<joj[i]<<" ";
}

