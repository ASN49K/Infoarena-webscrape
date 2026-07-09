//euclid prin impartire
#include<fstream>
using namespace std;
int main()
	{ifstream fin("euclid2.in");
	 ofstream fout("euclid2.out");
	 long a,b,nr,r,i;
	 fin>>nr;
	 for(i=1;i<=nr;i++)
		{fin>>a>>b;
	     r=a%b;
	     while(r)
				{a=b;
			     b=r;
				 r=a%b;
			    } 
		 fout<<b<<'/n';
		}
	 return 0;
	}
