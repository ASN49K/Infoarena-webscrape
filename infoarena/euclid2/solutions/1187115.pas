program euclid2;
var
n,m,i,j,k,a,b:longint;
f1,f2:text;
begin
assign (f1,'euclid2.in');
assign (f2,'euclid2.out');
reset (f1);
rewrite (f2);
readln (f1,n);
for i:=1 to n do
begin
readln (f1,a,b);
k:=1;
while k<>0 do
begin
k:=a mod b;
a:=b;
if k<>0 then b:=k;
end;
writeln (f2,b);
end;
close (f1);
close (f2);
end.
