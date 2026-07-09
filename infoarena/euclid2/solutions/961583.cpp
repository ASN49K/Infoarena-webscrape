using namespace std;
#include<fstream>
ifstream eu("euclid2.in");
ofstream tu("euclid2.out");
int main()
{
int N,a,b,c,i;
eu>>N;
for(i=1;i<=N;i++)
{
	eu>>a>>b;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
	}
	tu<<a<<"\n";
}
return 0;
}

