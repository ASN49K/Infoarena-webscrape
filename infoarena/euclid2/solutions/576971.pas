program cmmdcomun;
var a,b,x,y,i,cmmdc,n:longint;
f,g:text ;
begin
assign (f,'euclid2.in'); reset (f);
assign (g,'euclid2.out'); rewrite (g);
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