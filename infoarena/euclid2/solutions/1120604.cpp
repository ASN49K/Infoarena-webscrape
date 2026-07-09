#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int i,n,a,b,t;
    fin>>n;
    for(i=1;i<=n;++i)
    {
       fin>>a>>b;
       while(b!=0)
       {
       t=b;
       b=a%b;
       a=t;
       }
       fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;   
}



