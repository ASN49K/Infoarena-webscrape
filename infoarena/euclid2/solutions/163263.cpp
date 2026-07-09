#include<fstream>
using namespace std;

int main()
{long max,min,aux,i,n,k,cm;
 ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");
 fin>>n;


 for(k=1;k<=n;k++)
   {fin>>max>>min;
    if(min>max) {aux=max;max=min;min=aux;}
    if(max==min) fout<<min<<endl;
	else if(min%max==0) fout<<min<<endl;
	      else{ for(i=min;i>=1;i--)
		      if(min%i==0 &&max%i==0) {cm=i;break;}
		   fout<<cm<<endl;
		   }

    }
 fin.close();
 fout.close();
 return 0;
 }