#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b;
int main(){
        int n;
        f >> n;
        for(int i = 1; i <= n; ++i){

            f >> a >> b;
            while(b){
                int c = a % b;
                a = b;
                b = c;
            }
           g << a << '\n';
        }
        f.close();
        g.close();
        return 0;

}
