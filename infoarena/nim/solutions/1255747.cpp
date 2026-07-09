#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t;
    fin>>t;
    while(t--)
    {
        int n,x,s;
        fin>>n>>x;
        s=x;
        for(int i=2;i<=n;i++){
            fin>>x;
            s=s xor x;
        }
        if(s)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    fin.close();
    fout.close();
    return 0;
}
