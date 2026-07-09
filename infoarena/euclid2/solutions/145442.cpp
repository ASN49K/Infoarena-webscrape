#include <fstream>
#include <iomanip>

using namespace std;

fstream fin("euclid2.in",ios::in);
fstream fout("euclid2.out",ios::out);

long a,b,d;

int main(){
   fin>>a>>b;
   while(d=a%b) {a=b; b=d;}
   fout<<b;
   fin.close(); fout.close();
system("Pause");
}

