#include <fstream>
#include<iostream>
using namespace std;

int cmmdc(int a, int b)
{
    if(a == 0)
        return b;
    while(b != 0)
    {
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}
int main()
{ int cate;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");
int n;
fin>>n;
for(int i=0;i<n;i++){
    int a ,b;
    fin>>a>>b;
    fout<<cmmdc(a,b)<<'\n';
}



    return 0;
}
