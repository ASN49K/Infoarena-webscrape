#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,v[2],aint[4],gcd;

void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = v[st];
        return;
    }
    else
    {
        int mij = (st + dr) / 2;
        build(nod+1,st,mij);
        build(nod+2*(mij-st+1),mij+1,dr);
        aint[nod] = __gcd(aint[nod+1],aint[nod+2*(mij-st+1)]);
    }
}

void query(int nod, int st, int dr, int qst, int qdr)
{
    if(qst <= st && dr <= qdr)
    {
        gcd = __gcd(gcd,aint[nod]);
        return;
    }
    else
    {
        int mij = (st + dr) / 2;
        if(qst <= mij)
            query(nod+1,st,mij,qst,qdr);
        if(qdr > mij)
            query(nod+2*(mij-st+1),mij+1,dr,qst,qdr);
    }
}

int main()
{
    for(int i = 1; i <= 2; i++)
        fin >> v[i];
    gcd = v[1];
    build(1,1,2);
    for(int i = 1; i <= 1; i++)
        query(1,1,2,1,2);
    fout << gcd;
    return 0;
}
