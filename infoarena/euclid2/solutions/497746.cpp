#include <iostream>
using namespace std;

inline int max(int a, int b) { return (a > b ? a : b); }
FILE *in,*out;
int ret,A,B;
int main() {
	in=fopen("euclid2.in","rt");
	out=fopen("euclid2.out","wt");
	int t;
	fscanf(in,"%d",&t);
	for(;t;t--)
	{
		ret = 1;
		fscanf(in,"%d %d",&A,&B);
		for (int i = 1; i*i <= A; ++i)
			if (A % i == 0) 
			{
				if (B % i == 0)
					ret = max(ret, i);
				if (B % (A/i) == 0)
					ret = max(ret, A/i);
			}
	}
	fprintf(out,"%d",ret);
	
	return 0;
}