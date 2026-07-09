#include<fstream>
using namespace std;
int a,b,r;

int cmmdc2(int a, int b)
{	while(b!=0){r=a%b;
				a=b;
				b=r;
			   }
return a;
}
int main()
{int i=0,t;
 ifstream cin("cmmdc2.in");
 ofstream cout("cmmdc2.out");
 cin>>t;
 while(i<t){	cin>>a;
				cin>>b;
				cout<<cmmdc2(a,b)<<"\n";
				i++;
			}


 cin.close();
 cout.close();
 return 0;
}