#inlude <bits/stc++.h>
using namespace std;

int main()
{ ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;
f>>t;
while(t--){
    int a, b;
    f>>a;
    f>>b;
    int m=max(a, b);
    int r=1;
    for(i=m;i<1;i--)
    if(a%i==0 && b%i==0) {r=i; break;}

    g<<r<<endl;
}
f.close();
g.close();
    return 0;
}
