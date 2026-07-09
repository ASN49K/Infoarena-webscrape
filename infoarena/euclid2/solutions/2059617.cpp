#include <iostream>
#include <fstream>

using namespace std;
  int cmmdc(int a,int b){
    while(a!=0 and b!=0)
    {
     if(a<b){b=b%a;}
     else{a=a%b;}
    }     
    if(a==0)    
    return b;      
    else return a;
      }
int main () {

  int n,a,b,i;
  ifstream myfile ("euclid2.in");
  ofstream myfile2 ("euclid2.out");

  if (myfile.is_open())
  {        
   myfile>>n;                       

   for(i=1;i<=n;i++)
   {
    myfile>>a>>b;
    myfile2<<cmmdc(a,b)<<"\n";
   }

    myfile.close();
    myfile2.close();
  }



  return 0;
}
