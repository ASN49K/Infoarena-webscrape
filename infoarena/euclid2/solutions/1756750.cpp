#include<fstream.h>
ifstream f("euclid2.in");ofstream g("euclid2.out");int t,a,b,r;int main(){f>>t;while(t--){f>>a>>b;while(b){r=a%b;a=b;b=r;}g<<a<<'\n';}return 0;}
