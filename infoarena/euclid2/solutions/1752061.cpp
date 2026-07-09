#include <iostream>
#include <fstream>
using namespace std;

int cmmdc (int a, int b){
   int r=a%b;
   while (r){
       a=b;
       b=r;
       r=a%b;
   }
   return b;
}

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int T,a,b;
    fin>>T;
    while (T){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
        T--;
    }

    return 0;
}
