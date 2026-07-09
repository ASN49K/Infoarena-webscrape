program cmmdc;
var f,g:text;
    d,i,r,t,x:longint;
begin
assign(f,'euclid.in');
assign(g,'euclid.out');
reset(f);
rewrite(g);
read(f,t);
for x:=1 to t do
begin readln(f);
read(f,d,i);
r:=d mod i;
while d mod i <>0 do
begin
r:=d mod i;
d:=i;
i:=r;
end;
writeln(g,r);
end;
close(g);
close(f);
end.

