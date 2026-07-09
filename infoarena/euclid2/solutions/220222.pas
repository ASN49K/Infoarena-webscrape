program euclidextins;
var i,a,b,r,d,n,aux:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do begin
  readln(f,a,b);
  if b<a then begin aux:=a; a:=b; b:=aux; end;
 r:=a mod b;
while r<>0 do begin
  a:=b;
  b:=r;
  r:=a mod b;
end;
d:=b;
writeln(g,d);
end;
close(f);
close(g);
end.