var f,g:text;a,b:longint;t,i,r:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do begin
readln(f,a,b);
if a>b then r:=a mod b
       else r:=b mod a;
while r<>0 do begin
a:=b;b:=r;
if a>b then r:=a mod b
       else r:=b mod a;
end;
writeln(g,b);
end;
close(f);
close(g);
end.
