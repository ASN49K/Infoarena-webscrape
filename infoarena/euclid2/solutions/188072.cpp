# include <iostream.h>
# include <math.h>
# include <fstream.h>
 fstream f("euclid2.in",ios::in);
 fstream g("euclid2.out",ios::out);
 int main () {
 int c;
 long a,b;
 f>>a;f>>b;
 f.close();
 while (b) { c=a%b;
	     a=b;
	     b=c;
	    }
 return a;
}


