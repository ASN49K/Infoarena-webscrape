       #include <fstream.h>
       #include <math.h>
       ifstream f("euclid2.in");
       ofstream g("euclid2.out");
       long a,b,t;
       int main(){
	f>>t;
	while (t){t--;
	f>>a;
	f>>b;
	while(a!=b){if(a>b) a=a-b; else b=b-a;}
	g<<a<<'\0'; }
      g.close();
      f.close();
      return 0; }