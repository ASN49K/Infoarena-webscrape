#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int m,int n){
  int r;

    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;

    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(true);

    return n;


}
int a,b;
int main(void){
	int n;
	cout<<"Nr de teste : " ; cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a>>b;
	  cout<<euclid(a,b)<<endl;
  		}
  		return 0;
}
