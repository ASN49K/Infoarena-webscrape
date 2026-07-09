#include <bits/stdc++.h>

using namespace std;
ifstream r("nim.in");
ofstream w("nim.out");
int main()
{
    int t;
    r>>t;
    while(t--){
        int n, a, XOR=0;
        r>>n;
        for(int i=0;i<n;i++){
            r>>a;
            XOR^=a;
        }
        if(XOR==0){
            w<<"NU\n";
        }
        else{
            w<<"DA\n";
        }
    }
    return 0;
}
