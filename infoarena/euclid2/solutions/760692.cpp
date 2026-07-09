#include <fstream>

using namespace std;

int main()
{
   //Deschiderea fisierelor de intrare
   ifstream fin("euclid2.in");
   ofstream fout("euclid2.out");
    
   //Declararea variabilelor
   unsigned int a=0,b=0,r=0,t=0;
   
   //Citim numarul de perechi
   fin>>t;
   
   //Pentru fiecare pereche aplicam Algoritmul lui Euclid prin impartiri
   for(register unsigned int i=0;i<t;i++)
   {
      fin>>a;
      fin>>b;
      
      r=a%b;
      
      while(r)
      {
         a=b;
         b=r;
         r=a%b;        
      }        
      
      //Afisam cmmdc-ul perechii
      fout<<b<<'\n';     
   } 
    
   //Inchiderea fisierelor de intrare
   fin.close();
   fout.close();
   return 0;   
}
