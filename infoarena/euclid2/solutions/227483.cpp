#include<fstream.h>  
   //using namespace std;  
int cmmdc();
int T, a, b;
int main()
{  
     ifstream fin("euclid2.in");  
     fin >> T;  
     int i;  
     ofstream fout("euclid2.out");  
     for(i = 0; i < T; i++)
     {  
       fin >> a >> b;  
     fout << cmmdc()<<'\n';  
     }  
     fin.close();  
     fout.close();  
  return 0;  
}
int cmmdc()
{  
     int rest;  
     while ( b )
     {  
       rest = a % b;  
       a = b;  
       b = rest;  
     }  
     return a;  
   }  

