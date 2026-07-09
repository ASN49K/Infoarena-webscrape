#include<fstream.h>
int gcf(long a, long b);
int main()
{
	long a,b;
   ifstream in("cmmdc.in");
   in>>a;
   in>>b;
   in.close();
   ofstream out("cmmdc.out");
   if(gcf(a,b)==1)out<<0;
   else out<<gcf(a,b);
   out.close();
   return 0;
}
int gcf(long a, long b)
{
	if(a%b==0)
   	return b;
   else return gcf(b,a%b);
}
