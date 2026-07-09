#include<fstream>  
#include<stdio.h> 

using namespace std; 

char A[1024],B[1024];
int nr;
  
int main()   
{   
ifstream f1("euclid3.in"); 
ofstream f2("euclid3.out");    

int M,N,i,a;
f1>>M>>N;
for(i=0;i<M;i++)
{
	f1>>a;
	A[a]++;
}
for(i=0;i<N;i++)
{
	f1>>a;
	if(A[a]){B[a]++;nr++;}
}

f2<<nr<<endl;
for(i=0;i<1024;i++)
	if(B[i])f2<<i<<' ';

f1.close();
f2.close();

return 0;}   