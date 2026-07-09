var a,b,r:longint;
f,g:text;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,a,b);
r:=a mod b;
while r<>0 do
begin
a:=b;
b:=r;
r:=a mod b;
end;
write(g,b); close(g);
close(f);
end.