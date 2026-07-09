#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");


int main()
{
    int n,r;
    pair<int,int> a;
    
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>a.first>>a.second;
        r=a.first%a.second;
        while(r)
        {
            a.first=a.second;a.second=r;r=a.first%a.second;
        }
        fout<<a.second<<'\n';
    }
    
    
    fin.close();
    fout.close();
    return 0;
}
