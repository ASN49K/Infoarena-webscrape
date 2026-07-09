#include<fstream>

using namespace std;
int t,a,b,d,i;
void citire()
{
	ifstream in("euclid2.in");
	in>>t;
	in>>a;
    in>>b;
}
void scriere()
{
	ifstream in("euclid2.in");
	if(a<b)   
    {   
        d=a;   
        a=b;   
        b=d; 
	    in>>a;
        in>>b;
        i++;		
    }   
    while(a%b && i<=t)   
    {   
        d=a%b;   
        a=b;   
        b=d;
		in>>a;
        in>>b;
        i++;
		
    }   

}
void afisare()
{
	ofstream out("euclid2.out");
	out<<b;
}

int main()
{
	citire();
	scriere();
	afisare();
	return 0;
}
