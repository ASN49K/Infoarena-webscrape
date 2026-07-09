#include <fstream.h>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long a,b,d;

int main(){
   fin>>a>>b;
   for(d=a%b;d;a=b,b=r) d=a%b;
   fout<<b;
   fin.close(); fout.close();
system("Pause");
}

