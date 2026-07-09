#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void gcdextended(int a, int b, int &d, int &x, int &y)
{
    if(b==0){
        x=1, y=0;
        d=a;
    }
    else{
        int x1, y1;
        gcdextended(b, a%b, d, x1, y1);
        x=y1;
        y=x1-(a/b)*y1;
    }

}

int main()
{
    int a, b, n;
    fin>>n;
    while(n--)
    {
        fin>>a>>b;
        int x=0, y=0, d;
        gcdextended(a, b, d, x, y);
        fout<<d<<"\n";
    }
    return 0;
}
