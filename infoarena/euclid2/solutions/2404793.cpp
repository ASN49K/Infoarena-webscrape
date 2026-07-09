#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in ");
ofstream fout("euclid2.out");
int main()
{
  int t,i,a,b;
  fin>>t;
  for(i=1;i<=t;i++){
    fin>>a;
    fin>>b;
    while(a!=b)
    {if(a>b)
        a-=b;
    else
        b-=a;
    }
    fout<<a<<endl;
  }

    return 0;
}
