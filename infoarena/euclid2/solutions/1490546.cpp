#include<iostream>
#include<fstream>
using namespace std;
int euclid(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else{b=b-a;}
    }
    return a;
}
int main()
{
    int k=0,v[50],i,j,n,a,b;
    ifstream fin("euclid.in");
    ofstream fout("euclid.out");
    fin>>n;
    for(i=1;i<=2*n;i++)
    {
        fin>>j;
        k++;
        v[k]=j;
    }
    i=1;
    while(i<=2*n)
    {
        a=v[i];
        i++;
        b=v[i];
        i++;
        fout<<euclid(a,b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
