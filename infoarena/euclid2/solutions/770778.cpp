#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    int a,m,n;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>a;
    for(int i=1;i<=a;i++)
    {
    fin>>n>>m;
    int x;
    while (n!=0)
    {
         x=n;
         n=m %n;
         m=x;
     } 
     fout<<m<<"\n";
     }    
    fin.close();
    fout.close();
    return 0;
}
