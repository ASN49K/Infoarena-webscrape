#include <iostream>
#include<fstream>
using namespace std;
int t,a,b,i;
int euclid(int a,int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }
    return 0;
    fout.close();
}
