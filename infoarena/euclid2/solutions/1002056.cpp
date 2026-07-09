#include<fstream>

using namespace std;

int divizor(int a,int b);
int main()
 {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int a,b,t;
    fin>>t;

    for(int i=0;i<t;i++)
        {
            fin>>a>>b;
            fout<<divizor(a,b)<<"\n";
        }
    fin.close();
    fout.close();



    return 0;
}

int divizor(int a, int b)
{
    if(a%b==0)
        return b;
    else
        return divizor(b,a%b);
}
