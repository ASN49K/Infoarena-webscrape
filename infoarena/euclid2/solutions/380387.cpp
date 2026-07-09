# include <fstream.h>
int main()
{long T,a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
while(T)
{f>>a>>b;
 r=a%b;
 while(r){a=b;b=r;r=a%b;}
 g<<b<<'\n';
 T--;
}
f.close();g.close();

return 0;
}