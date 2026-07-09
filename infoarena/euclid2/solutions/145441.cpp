#include <fstream>
#include <iomanip>

using namespace std;

fstream fin("euclid2.in",ios::in);
fstream fout("euclid2.out",ios::out);

long a,b,d;

int main(){
   fin>>a>>b;
   for(d=a%b;d;) {a=b; b=d;d=a%b;}
   fout<<b;
   fin.close(); fout.close();
system("Pause");
}

