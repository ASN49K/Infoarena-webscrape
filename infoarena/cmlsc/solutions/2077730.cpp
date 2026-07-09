/*
ID: mihnea.2
TASK:  friday
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("q.in");
ofstream fout("q.out");
int an=1900,luna=1,zi=1,wzi=1,sl=0,n,su[15];
/**
1  jan
2  feb
3  mar
4  apr *
5  mai
6  juni *
7  july
8  august
9  september *
10 october
11 november *
12 december
**/
bool leap(int an)
{
    if(an%400==0)
    {
        if(an%1000==0)
            return 1;
        return 0;
    }
    if(an%4==0)
        return 1;
    return 0;
}
int nxt()
{
    ///cout<<zi<<" "<<luna<<" "<<an<<"\n";
    if(an==1900+n)
        return 0;
    if(zi==13)
        su[wzi]++;
    wzi++;
    if(wzi==8)
        wzi=1;
    if(luna==1)
    {
        if(zi==31)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==2)
    {
        if(leap(an))
        {
            if(zi==29)
            {
                luna++;
                zi=1;
                return 1;
            }
        }
        if(leap(an)==0)
        {
            if(zi==28)
            {
                luna++;
                zi=1;
                return 1;
            }
        }
        zi++;
    }
    if(luna==3)
    {
        if(zi==31)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==4)
    {
        if(zi==30)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==5)
    {
        if(zi==31)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==6)
    {
        if(zi==30)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==7)
    {
        if(zi==31)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==8)
    {
        if(zi==31)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==9)
    {
        if(zi==30)
        {
            zi=1;
            luna++;
            return 1;
        }
        else
            zi++;
    }
    if(luna==10)
    {
        if(zi==31)
        {
            luna++;
            zi=1;
            return 1;
        }
        else
            zi++;
    }
    if(luna==11)
    {
        if(zi==30)
        {
            zi=1;
            luna++;
            return 1;
        }
        else
            zi++;
    }
    if(luna==12)
    {
        if(zi==31)
        {
            an++;
            zi=luna=1;
            return 1;
        }
        else
            zi++;
    }
    return 1;
}
int main()
{
    fin>>n;
    while(nxt())
    {

    }
    fout<<su[6]<<" "<<su[7]<<" ";
    for(int i=1;i<=5;i++)
        fout<<su[i]<<" ";
    fout<<"\n";
    return 0;
}
