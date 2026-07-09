#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin>>t;
    while (t!=0)
    {
        int a,b;
        fin>>a>>b;
        int r=a%b;
        while (r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<"\n";
        t--;
    }
    fin.close();
    fout.close();
}
