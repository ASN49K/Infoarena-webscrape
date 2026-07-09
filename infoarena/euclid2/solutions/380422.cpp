       #include <fstream.h>
       #include <math.h>
       ifstream f("euclid2.in");
       ofstream g("euclid2.out");
       unsigned a,b,t;
       void main(){
	f>>t;
	while (t){t--;
	f>>a;
	f>>b;
	while(a!=b){if(a>b) a=a-b; if(a<b) b=b-a;}
	g<<a;
	g<<'\0'; }
      g.close();
      f.close();
       }