#include <bits/stdc++.h>
using namespace std;

long N, cnt;
long long prim[2000005];

int main(void)
{
    int i, j;
    
    ifstream fin("ciur.in");
    ofstream fout("ciur.out");

    fin>>N;

    for (i = 2; i <= N; ++i){
        if (prim[i]!=1){
            ++cnt;
            for (j = i+i; j <= N; j += i)
                prim[j] = 1;
        }
    }
    
    
    fout<<cnt;

}
