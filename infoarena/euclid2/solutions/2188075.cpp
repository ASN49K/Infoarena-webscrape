#include <fstream>
 
using namespace std;
 
int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int x;
    fin>>x;
    for (int var=0;var<x;var++)
    {
        int a,b;
        fin>>a>>b;
        while (b>0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }
}