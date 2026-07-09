#include<fstream>
#include<vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n;
vector<int> A,B;
void citire()
{in>>m>>n;
 int x,i;
 for (i=0;i<m;i++)
     {in>>x;
      A.push_back(x);
     }
 for (i=0;i<n;i++)
	 {in>>x;
	  B.push_back(x);
     }
 /* afisare
 for (i=0;i<A.size();i++)
	 out<<A[i]<<" ";
 out<<endl;
 for (i=0;i<B.size();i++)
	 out<<B[i]<<" ";
 */
}
void subsir()
{int i,j,nr=0;
 vector<int> C;
  for (i=0;i<A.size();i++)
	  for (j=0;j<B.size();j++)
	    if (A[i]==B[j]) {C.push_back(A[i]); nr++;}
 out<<nr<<endl;
 for (i=0;i<C.size();i++)
	 out<<C[i]<<" ";
}
int main()
{	citire();
    subsir();
	return 0;
}
