#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    else
        cmmdc(b,a%b);
}

int main()
{
    ifstream  fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin>>n;
    int a,b;
    for(int i=0;i<n;i++)
        {
            fin>>a>>b;
            cout<<cmmdc(a,b)<<'\n';
        }
    return 0;
}
