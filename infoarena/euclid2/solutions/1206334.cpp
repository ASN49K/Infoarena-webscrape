#include<fstream>
using namespace std;
long euclid(long a,long b){
	if(b==0)
		    return a;
	long m=a%b;
			while(m){
				a=b;
				b=m;
				m=a%b;
			}
		return b;
}
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n;
long a,b;
int main()
{
    in>>n;
    for(int i=1;i<=n;i++)
        {
            in>>a>>b;
            out<<euclid(a,b)<<endl;

        }
	return 0;
}

