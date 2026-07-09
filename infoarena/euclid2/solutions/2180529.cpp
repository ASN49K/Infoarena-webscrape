#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int main()
{
    int i,n,a,b,c;
    fin>>n;
    for(i=0;i<n;i++)
    {fin>>a>>b;
    if(b>a) swap(a,b);
    while(b){
       c=a%b;
       a=b;
       b=c;
    }
    fout<<a<<endl;
    }
    return 0;
}
