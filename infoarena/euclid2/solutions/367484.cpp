using namespace std;
#include<fstream.h>
int main()
{ ifstream f("euclid2in.txt",ios::in);
  ofstream g("euclid2out.txt",ios::out);
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