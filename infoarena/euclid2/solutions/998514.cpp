// Algoritmul lui euclid prin impartiri
#include<fstream>
using namespace std;

int cmmdc(int a, int b);

int main()
{
    int T,a,b;
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

int cmmdc(int a, int b)
{
    if(a%b==0) return b;
       else if(b%a==0) return a;
               else return cmmdc(b,a%b);
}
