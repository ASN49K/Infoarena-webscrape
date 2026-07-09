#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b){
int r;
while(b!=0){
r=a%b;
a=b;
b=r;
}
return a;
}
int main()
{ifstream fin("euclid1.in");
ofstream fout("euclid2.out");
    int T, a,b;
    fin>>T;
    for(int i=1;i<=T;i++)
    {fin>>a>>b;
    fout<<cmmdc(a,b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
