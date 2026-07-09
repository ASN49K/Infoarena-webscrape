#include<iostream>
 #include <fstream>
using namespace std;
int main ()
{
   ifstream fin ("euclid2.in");
   ofstream fout ("euclid2.out");
    int T,n1,n2,r;
    fin>>T;
    for(int i=1; i<=T; i++)
    {
        fin>>n1>>n2;
        while(n2)
        {
            r=n1%n2;
            n1=n2;
            n2=r;
        }
        fout<<n1<<" ";
    }
    return 0;
}
