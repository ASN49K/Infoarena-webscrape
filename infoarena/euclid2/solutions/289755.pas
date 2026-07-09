var f,g:text; i,n,a,b:longint;
procedure euclid1;
var r:longint;
begin
while b<>0 do
begin
r:=a mod b;
a:=b;
b:=r;
end;
writeln(g,a);
end;
procedure euclid2;
var r:longint;
begin
while a<>0 do
begin
r:=b mod a;
b:=a;
a:=r;
end;
writeln (g,b);
end;
begin
assign (f,'euclid2.in');
reset (f);
readln (f,n);
assign (g,'euclid2.out');
rewrite (g);
for i:=1 to n do
begin
read (f,a);
read (f,b);
if a>b then
euclid1
else euclid2;
end;
close (f);
close (g);
end.
