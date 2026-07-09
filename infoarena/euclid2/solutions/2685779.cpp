#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void get(int a,int b)
{   if(a<b)swap(a,b);
b=b%a;
while(b!=0)
{
    swap(a,b);
    b=b%a;
}
fout<<a<<endl;
}
int main()
{
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;++i)
    {
        fin>>a>>b;
        get(a,b);
    }
    return 0;
}
