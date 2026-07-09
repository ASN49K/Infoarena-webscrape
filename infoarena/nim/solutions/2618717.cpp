#include <iostream>
#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t;
    in>>t;
    for(int i = 1; i <= t; i++){
        int n;
        in>>n;
        int ans = 0;
        for(int j = 1; j <= n; j++){
            int x;
            in>>x;
            ans ^= x;
        }
        if(ans == 0)
            out<<"NU";
        else
            out<<"DA";
        out<<'\n';
    }
    return 0;
}
