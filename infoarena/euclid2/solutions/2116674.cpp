#include <iostream>
#include <fstream>
using namespace std;
int cmmdc_Stein(int,int);
int main()
{
    int a,b,cmmdc,t;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(;t;t--)
    {
        fin>>a>>b;
        fout<<cmmdc_Stein(a,b)<<'\n';
    }   
    return 0;
}
int cmmdc_Stein(int u,int v)
{
    if(u==v) return u;
    if(u==0) return v;
    if(v==0) return u;
    int k;   //Cea mai mare putere a lui 2 care divide pe u si v
    for(k=0;((u | v) & 1)==0;k++)
    {
        u>>=1;
        v>>=1;
    }
    // Se imparte u la 2 pana cand devine impar
    while((u & 1)==0) u>>=1;
    // In continuare u va fi tot timpul impar
    do{
        // Se imparte v la 2 cat timp este par
        while((v & 1)==0) v>>=1;
        // Acum u si v sunt impare. Daca u > v atunci se interschimba
        if(u>v)
        {
            u=u^v;
            v=u^v;
            u=u^v;
        }
        v=v-u;
    }while(v != 0);
    return u<<k;
}
