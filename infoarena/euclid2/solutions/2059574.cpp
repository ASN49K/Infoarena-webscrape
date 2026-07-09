#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  //string line;
  int x,n,a,b,i;
  ifstream myfile ("euclid2.in");
  ofstream myfile2 ("euclid2.out");
  if (myfile.is_open())
  {        
   myfile>>n;                       
   x=1;
   for(i=1;i<=n;i++)
   {
    myfile>>a>>b;
    x=1;
    while(a!=b)
    {
     if(a<b){b=b-a;}
     else{a=a-b;}
    }     
    x=a;
    myfile2<<x<<"\n";
   }
   while(! (myfile.eof())  )
    {
           myfile>>x;
           cout<<x<<'\n';
      //cout << line << '\n';
    }
    myfile.close();
    myfile2.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
