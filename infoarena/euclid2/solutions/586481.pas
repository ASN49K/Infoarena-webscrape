Program Euclid2;
var i,t,x,y,r:longint;
    f1,f2:text;

Function Euclid(a,b:longint ) : longint;
 begin
  while a<>b do
    if a>b then a:=a-b
           else b:=b-a;
  Euclid:=a;
 end;

begin
assign(f1,'euclid2.in'); reset(f1);
assign(f2,'euclid2.out'); rewrite(f2);
readln(f1,t);
for i:=1 to t do
 begin
  readln(f1,x,y);
  r:=euclid(x,y);
  writeln(f2,r);
 end;
close(f1); close(f2);
end.

