#include<fstream>
#include<iostream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("clmsc.out");

int main()
{
	int m,n,i,j,a[1025],b[1025],c[1025],k=0;
	in>>m>>n;
	cout<<"m este "<<m<<"\n";
	cout<<"n este "<<n<<"\n";
	for(i=0;i<m;i++)
		in>>a[i];
	for(j=0;j<n;j++)
		in>>b[j];
	cout<<"Avem a= ";
	for(i=0;i<m;i++)
		cout<<a[i]<<" ";
	cout<<"\nAvem b= ";
	for(j=0;j<n;j++)
		cout<<b[j]<<" ";
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(a[i]==b[j])
			{
				c[k]=a[i];
				k+=1;
			}
			for(i=0;i<k;i++)
			{
				cout<<c[i]<<" ";
				out<<c[i]<<" ";
			}
			return 0;
}