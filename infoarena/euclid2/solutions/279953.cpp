#include<iostream>
#include<fstream>
int main ()
{
	int t,a,b,i;
	std::ifstream fin("euclid.in");
	std::ofstream fout("euclid.out");
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a;      
    fin>>b;      
    while(a!=b)       
    {      
        if(a>b)      
            a=a-b;      
        else     
            b=b-a;      
    }      
		fout<<a<<std::endl;
	}
	fin.close();
	fout.close();
	return 0;
}