#include <iostream>
#include <fstream>

using namespace std;

int main()

{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,i,s;
    fin>>a>>b;
   for(i=1;i>a;i++)
   {
       s=a/i;
       if(b%s==0)
       {
         fout<<s;
         goto loop;
       }
   }

 loop:
     fin.close();
     fout.close();
      return 0;
}
