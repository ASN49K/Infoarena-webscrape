#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void get(int a,int b)
{

    while(true)
    {
        if(a>b)a=a-b;
        else b=b-a;
        if(a%b==0){fout<<b<<endl;break;}
        else if(b%a==0){fout<<a<<endl;break;}
    }
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
