#include <fstream>
std::ifstream fin("euclid2.in");     
std::ofstream fout("euclid2.out");
int main ()
{
    int n,a,b,i;
    fin>>n;
    for(i=0;i<n;i++)
    {
                    fin>>a;
                    fin>>b;
    while((a>0)&&(b>0))   
    {                    if(a>b)   
                         a=a-b;   
                         else   
                         b=b-a;   
}   
if((a!=1)&&(b!=1))   
   if(a>0)   
   fout<<a<<"\n";   
   else   
   fout<<b<<"\n"; 
   else   
fout<<"1 \n";; 
}  
}

                                         
