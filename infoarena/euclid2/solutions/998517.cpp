// Algoritmul lui euclid prin impartiri
#include<fstream>
using namespace std;
long cmmdc(long a, long b);

int main()
{
    long T,a,b;
    ifstream inFile("euclid2.in");
    inFile>>T;

    ofstream outFile;
    outFile.open("euclid2.out");

    for(int i=1;i<=T;i++){
        inFile>>a>>b;
        outFile<<cmmdc(a,b)<<endl;
    }
   // outFile.close();
}

long cmmdc(long a, long b)
{
    if(b==0) return a;
       else return cmmdc(b,a%b);
}
