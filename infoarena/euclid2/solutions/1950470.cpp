#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in"); ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
    if(!b) return a; else
   return cmmdc(b,a%b);
}

int main() {
    int n,a,b;
	in>>n;
	int i=0;
	while(i<n)
	{
	    in>>a>>b;
	  out <<cmmdc (a,b) <<'\n';
	   i++;
	}
	return 0;
}