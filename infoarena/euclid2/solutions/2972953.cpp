#include <iostream>
#include <cstring>
using namespace std;
int i=0, j=0,ok;
char s1[22], s2[22];

int main()
{
    cin.get(s1,22);
    char *p=strtok(s1," ");
    p=strtok(NULL," ");
    cout<<p;
    strcpy(s2,p);

    strcat(s2,"2022");
    cout<<s2;
    return 0;
}
