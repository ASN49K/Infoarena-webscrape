#include<fstream>
using namespace std;

int main(){

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int r=0,a,b,x ;

cin>>x;

while(x)
{
  cin>>a>>b;
if(a>b)
    swap(a,b);

while(a)
{
    r=b%a;
    b=a;
    a=r;
}
cout<<b<<'\n';
--x;
}

cin.close();
cout.close();

return 0;
}
