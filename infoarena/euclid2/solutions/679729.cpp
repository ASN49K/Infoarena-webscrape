#include<iostream>
#include<fstream>

using namespace std;

int cv=0, l=0, logic=0;
char x;
int main()

{

ifstream fin("text.in");
ofstream fout("text.out");
x=fin.get();
while(x!=EOF)
{if( (x>='a' && x<='z') || (x>='A' && x<='Z') )
{l++;
if(!logic)
{logic= 1;
cv++;}}
else
{
logic=0;
}x=fin.get();
}
fout<<l/cv;
fin.close();
fout.close();
return 0;
}
