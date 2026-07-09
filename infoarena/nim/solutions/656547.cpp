#include <fstream>
using namespace std;
int main(){
    int t,n,x,sum;
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>t;
    while(t){
     t--;
     f>>n;
     sum=0;
     while(n){
      n--;
      f>>x;
      sum=sum^x;
     }
     if(sum) g<<"DA\n";
     else g<<"NU\n";
    } 
    return 0;
}
