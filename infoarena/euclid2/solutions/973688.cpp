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
	     while(b)
				{r=a%b;			     
				 a=b;
				 b=r;
			    } 
		 if(a==1) fout<<0;
		 else fout<<a<<'/n';
		}
	 return 0;
	}
