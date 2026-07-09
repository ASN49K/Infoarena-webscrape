program cmmdc;
var a,b,n,i,t:integer;
k:shortint;
f1,f2:text;
begin
assign(f1,'euclid.in');
assign(f2,'euclid.out');
reset(f1);
rewrite(f2);
readln(f1,n);
i:=0;
for i:=1 to n do
begin
readln(k);
while b<>0 do
t:=b;
b:=a mod b;
a:=t;
writeln(f2,a);
close(f1);
close(f2);
end;
end.
