#include<fstream> 
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
 
int main (){
int  n , t, sum , x;   
 
f>>t;
 
for(;  t ; --t){

f>>n ;
 
sum=0;
 
for(int  i= 1; i <= n ;  ++ i){
 
f>>x;
 
sum=sum^x;
 
}
 
if( sum == 0 )
g<<"NU\n";
else
g<<"DA\n";
 
 
}
 
return 0;
}