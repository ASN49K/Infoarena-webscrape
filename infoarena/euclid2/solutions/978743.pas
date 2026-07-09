var a,b,k,l:int64;
i,t:longint;
f,g:text;

begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
read(f,t);
for i:=1 to t do begin
read(f,a,b);
l:=b;
k:=a mod b;
while k<>0 do begin
l:=k;
a:=b;
b:=k;
k:=a mod b;
end;
writeln(g,l);
end;
close(g);
close(f);
end.