#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    unsigned i,n,a,b;
    fin>>n;
    for(i=1;i<=n;++i)
    {
       fin>>a>>b;
       while(a!=b)
       {
       if(a>b)
       a=a-b;
       else b=b-a;
       }
       fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;   
}



