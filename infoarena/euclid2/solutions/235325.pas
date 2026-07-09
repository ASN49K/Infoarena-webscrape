program euclid;
var f,g:text;
    i,t,a,b,r:longint;
begin
assign(f,'euclid.in');
assign(g,'euclid.out');
reset(f);
rewrite(g);
read(f,t);
for i:=1 to t do
begin
readln(f,a,b);
if a<b then begin r:=a;a:=b;b:=r; end;
r:=a mod b;
while r<>0 do
begin
a:=b;
b:=r;
r:=a mod b;
end;
writeln(g,b);
end;
close(f);
close(g);
end.

