#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin>>T;
    int a , b ,r;
    int cmmdc,i;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
         int r=a%b;
         while(b!=0)
         {
             a=b;
             b=r;
             r=a%b;
         }
         fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
