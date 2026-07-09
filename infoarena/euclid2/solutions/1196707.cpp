#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    string line;
    ifstream si("sec.in.txt");
    ofstream so("sec.out.txt");
    int  contor,a,b;


  if (si.is_open())
   {
    si>>contor;
    for(contor;contor;--contor)
    {
            si>>a>>b;
            while (a!=b)
            {
             if (a>b)
                a=a-b;
              else
                b=b-a;
            }
            cout << a <<endl;
    }
   }
   else cout<<"unable to open file"<<endl;
}

