#include <iostream>
#include <fstream>
#include <string>
using namespace std;
  int cmmdc(int a,int b){
    while(a!=b)
    {
     if(a<b){b=b-a;}
     else{a=a-b;}
    }         
    return a;      
      }
int main () {
  //string line;
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

//  else cout << "Unable to open file"; 

  return 0;
}
