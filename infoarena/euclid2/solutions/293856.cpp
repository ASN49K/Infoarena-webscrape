#include<iostream>
#include<string>

using namespace std;

void func(string p="Genereic message: ");

int main()
{string q;
cin>>q;
if(q.empty())
func();
else
    func(q);
cout<<"\n\n\n\nPress the enter key to exit";
cin.ignore(cin.rdbuf()->in_avail()+1);
cin.ignore(cin.rdbuf()->in_avail()+1);
}

void func(string p)
{cout<<p;
int x;
cin>>x;
cout<<endl<<x;
}
