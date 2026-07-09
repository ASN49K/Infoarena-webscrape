# include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long long n;
    fin >> n;
    for(int i = 1; i <= n; i++){
        long long x , y;
        fin >> x >> y;
        while(y != 0){
            int r = x % y;
            x = y;
            y = r;
        }
        fout << x << endl;
    }
    
    return 0;
}