using namespace std;
#include<fstream.h>
int main()
{ fstream f("euclid2.in.txt",ios::in);
  fstream g("euclid2.out.txt",ios::out);
  float a,b,T,i;
  f>>T;
  for(i=1; i<=T; i++)
  { f>>a>>b;
    while(a!=b)
		if(a>b)
			a=a-b;
		else
			if(a<b)
				b=b-a;
    g<<a<<endl;
  }
   f.close(); g.close();
  return 0;
}  