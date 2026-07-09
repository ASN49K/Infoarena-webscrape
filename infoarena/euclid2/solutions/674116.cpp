#include<fstream> 
using namespace std; 
ifstream fin("euclid2.in"); 
ofstream fout("euclid2.out"); 
int T,a,b; 
int d(int a, int b) 
{
	if(b==0)return a;
	return d(b, a%b); 
} 
int main() 
{ 
	fin>>T; 
	for(int i=1;i<=T;i++) 
	{    
		fin>>a>>b; 
		fout<<d(a,b)<<endl;     
	}   
	return 0; 
}