var a,b,r,n:integer;
    f,g:text;
begin
assign(f,'cmmdc.in');
assign(g,'cmmdc.out');
reset(f);
rewrite(g);
read(f,n);
for i:=1 to do begin
read(f,a);
read(f,b);
r:=a mod b;
while(r<>0) do begin
a:=b;
b:=r;
r:=a mod b;
end;
write(g,b);
close(f);
close(g);
end.