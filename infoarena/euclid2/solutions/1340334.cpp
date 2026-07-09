#include<fstream>
#include<cstring>
using namespace std;
ifstream f("cezar.in"); ofstream g("cezar.out");
char cuv[2002];
int main()
{   f>>cuv;
    for(int i=0;i<strlen(cuv);i++)
        if(cuv[i]!=cuv[i+1]) cuv[i]=cuv[i+1];
            else cuv[i]='a';
    for(int i=0;i<strlen(cuv);i++) g<<cuv[i];
    g.close(); return 0;
}
