#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int T;
    fin >> T;
    for(int t=1;t<=T;t++){
        int n,sum=0,x;
        fin >> n;
        for(int i=1;i<=n;i++){
            fin >> x;
            sum^=x;
        }
        if(sum==0) fout << "NU" << '\n';
        else fout << "DA" << '\n';
    }
    return 0;
}
