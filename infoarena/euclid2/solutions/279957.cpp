#include<iostream>
#include<fstream>
int main ()
{
	int t,a,b,i,c,r;
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	fin>>t;
	for(i=1;i<=t;i++)
	{
	fin>>a;   
    fin>>b;   
    do  
    {   
        r=a%b;   
        a=b;   
        b=r;   
    }while(r);   
    c=a;   
    fout<<c<<std::endl;   

	}
	fin.close();
	fout.close();
	return 0;
}