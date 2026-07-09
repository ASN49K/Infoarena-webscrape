program euclid2;
var
n,m,i,j,k,a,b:longint;
f1,f2:text;
function cmmdc(x,y:longint):longint;
var
r:longint;
begin
while y<>0 do begin
r:=x mod y;
x:=y;
y:=r;
end;
cmmdc:=x;
end;
begin
assign (f1,'euclid2.in');
assign (f2,'euclid2.out');
reset (f1);
rewrite (f2);
readln (f1,n);
for i:=1 to n do
begin
readln (f1,a,b);
writeln (f2,cmmdc(a,b));
end;
close (f1);
close (f2);
end.
