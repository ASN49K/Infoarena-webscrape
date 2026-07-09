program eucliud;
var g,f:text;
a,b:real;
t:1..100;
procedure min(a,b:real);
begin
while a<>b do
if a>b then a:=a-b
else if b>a then b:=b-a;
writeln(g,a:4:2);
end;
procedure cmmdc(t:byte;a,b:real);
begin
if t=1 then
begin
min(a,b);
close(g);
close(f);
end
else
begin
min(a,b);

readln(f,a,b);
cmmdc(t-1,a,b);
end;
end;
begin
assign(f,'euclid2.in');
reset(f);
readln(f,t);
readln(f,a,b);
assign(g,'euclid2.out');
rewrite(g);
cmmdc(t,a,b);
readln;
end.


