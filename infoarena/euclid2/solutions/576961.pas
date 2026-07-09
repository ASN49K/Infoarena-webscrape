program cmmdcomun;
var a,b,x,y,i,cmmdc,n:longint;
f,g:text ;
begin
assign (f,'cmmdc.in'); reset (f);
assign (g,'cmmdc.out'); rewrite (g);
read (f,n);
for i:=1 to n do
begin
read (f,a,b);
while (a<>b) and (a<>0) and (b<>0) do
 if (a>b) then a:=a-b
          else b:=b-a;
if (a=1) then a:=0;
writeln (g,a);
end;
close (f);
close (g);
end.
program cmmdcomun;
var a,b,x,y,i,cmmdc:longint;
f,g:text ;
begin
assign (f,'cmmdc.in'); reset (f);
assign (g,'cmmdc.out'); rewrite (g);
read (f,a,b); cmmdc:=1;
for i:=1 to a do
if (a mod i=0) and (b mod i=0) then cmmdc:=i;
if cmmdc=1 then cmmdc:=0;
writeln (g,cmmdc);
close (f);;
close (g);
end.