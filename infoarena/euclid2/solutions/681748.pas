program euclid;
var t,a,b,i:longint;
    f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
read(f,t);
i:=1;
while i<=t do begin
read(f,a,b);
while a<>b do begin
if a>b then a:=a-b
else b:=b-a;
end;
write(g,a);
i:=i+1;
close(f);close(g);
end;
end.