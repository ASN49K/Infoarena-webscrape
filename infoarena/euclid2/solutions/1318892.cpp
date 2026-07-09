#include <fstream>
#include <iostream>
using namespace std;
int n,m,a[100002],tip,i,nr,st,dr,mid;
int cautbin0(int nr,int n)
{
    int st,dr,mid;
    ifstream fin("cautbin.in");
    ofstream fout("cautbin.out");
    st=1;
    dr=n;
    while(st<=dr)
        {
            mid=(st+dr)/2;
            if(a[mid]<=nr)
            {
                st=mid+1;
            }
            else
            {
                dr=mid-1;
            }
        }
        if(a[dr]==nr)
        {
            return dr;
        }
    else return -1;
    fin.close();
    fout.close();
}
int cautbin1(int nr,int n)
{
    int st,dr,mid;
    ifstream fin("cautbin.in");
    ofstream fout("cautbin.out");
        st=1;
        dr=n;
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if(a[mid]<=nr)
            {
                st=mid+1;
            }
            else
            {
                dr=mid-1;
            }
        }
        return dr;
            fin.close();
    fout.close();
}
int cautbin2(int nr,int n)
{
    int st,dr,mid;
    ifstream fin("cautbin.in");
    ofstream fout("cautbin.out");
    st=1;
    dr=n;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(a[mid]<nr)
        {
            st=mid+1;
        }
        else
        {
            dr=mid-1;
        }
    }
    return st;
    fin.close();
    fout.close();
}
int main ()
{
    ifstream fin("cautbin.in");
    ofstream fout("cautbin.out");
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>a[i];
    fin>>m;
    for(i=1;i<=m;i++)
    {
        fin>>tip;
        fin>>nr;
        if(tip==0)
        {
            fout<<cautbin0(nr,n)<<'\n';
        }
        if(tip==1)
        {
          fout<<cautbin1(nr,n)<<'\n';
        }
        if(tip==2)
        {
            fout<<cautbin2(nr,n)<<'\n';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
