var a,b,r,n,i:integer;
    f,g:text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,n);
for i:=1 to n do begin
read(f,a);
read(f,b);
r:=a mod b;
while(r<>0) do begin
a:=b;
b:=r;
r:=a mod b;
end;
write(g,b);
end;
close(f);
close(g);
end.