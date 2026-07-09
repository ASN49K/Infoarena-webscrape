#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;
 int t,a,b;
int prim(int a,int b)
{
    while(b!=0) if(a>b)a-=b;
                  else b-=a;
             return a;
}                
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin>>t;
    for(int i=1;i<=t;++i)
    {
            fin>>a;'\n';
            fin>>b;'\n';
            fout<<(prim(a,b))<<'\n';
    }
    return 0;
}
    
    
    
