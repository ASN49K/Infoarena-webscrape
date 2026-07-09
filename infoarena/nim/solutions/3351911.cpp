#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n;
void test(){
    int s = 0;
    fin >> n;
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++){
        fin >> a[i];
        s = s ^ a[i];
    }
    if(s == 0) fout << "NU\n";
    else fout << "DA\n";
}
int main(){
    int t;
    fin >> t;
    while(t--){
        test();
    }

    return 0;
}