#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, a, b;
    fin >> n;
    
    for(int i = 0; i < n; i++){
        fin >> a >> b;
        
        while(b){
            a %= b;
            swap(a, b);
        }
        
        fout << a << endl;
    }
    return 0;
}