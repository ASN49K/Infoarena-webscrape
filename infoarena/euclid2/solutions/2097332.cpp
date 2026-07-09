{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf200
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include <fstream>\
\
using namespace std;\
ifstream fin ("euclid2.in");\
ofstream fout("euclid2.out");\
\
int d=1,law=1;\
void dosomething(int a,int b)\{\
	if(a%d==0 && b%d==0)\
	law=d;\
	if(d<=a &&d <=b)\{\
	d++;\
	dosomething(a,b);\
	\}\
\}\
int main() \{\
	int a,b,c;\
	cin>>c;\
	for(int i=0;i<c;i++)\{\
		cin>>a>>b;\
		dosomething(a,b);\
		cout<<law<<endl;\
		law=1;\
		d=1;\
	\}\
	\
\}}