#include <iostream>
#include <fstream>
using namespace std;

int main()
{   ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n,x,y,r;
    fin>>n;
    while(n!=0){
       fin>>x>>y;
       while(y!=0){
            r=x%y;
            x=y;
            y=r;
          }
          fout<<x;
          fout<<endl;
          n--;
       }
   return 0;
}
