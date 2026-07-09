#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int euclid(int a,int b)
{
    while(a!=b)
     if(a>b)
      a=a-b;
      else
      b=b-a;
    return a;
}
int main()
{
    fin>>n;
    int i;
    for(i=1;i<=n;i++){
     fin>>a>>b;
     fout<<euclid(a,b)<<'\n';}
    fin.close();fout.close();
    return 0;
}
