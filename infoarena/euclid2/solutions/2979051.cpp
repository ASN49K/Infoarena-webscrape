/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<fstream>
using namespace std;
int cmmdc(int a,b) 
   {
        while(b!=0) 
        {
        int d=a%b;
        a=b;
        b=d;
        }
    return a;
   }
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, a, b, 
int main()
{
  
    fin>>n;
    for(int i=1;i<=n;i++)
    {
     fin>>a,b;
    fout<<cmmdc(a,b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}


    
         