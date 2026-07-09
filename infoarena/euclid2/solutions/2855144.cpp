#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int algoritm(int a, int b){
    while (b!=0) {
        int r=a%b;
        a=b;
        b=r;
    }

    return a;
}
int main()
{int n,x,y;
fin>>n;
for (int i=0; i<n; i++)
{
    fin>>x>>y;
    fout<<algoritm(x, y)<<endl;
}


    return 0;
}
