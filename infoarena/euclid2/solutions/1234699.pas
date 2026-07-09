program oo;
var
a,b,t:int64;
n,i:longint;
f1,f2:text;
begin
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
reset(f1);
rewrite(f2);
readln(f1,n);
for i:=1 to n do
begin
readln(f1,a,b);
while b<>0 do
begin
t:=b;
b:=a mod b;
a:=t
end;
writeln(f2,a);
end;
close(f1);
close(f2)
end.

