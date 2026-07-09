var c,a,b,n,i,k:longint;
  g,f:text;
begin

assign(g,'euclid2.out');
rewrite(g);
assign(f,'euclid2.in');
reset(f);
readln(f,n);
for i:=1 to n do begin
readln(f,a,b);
while(b<>0) do begin
  c:= a mod b;
  a:=b        ;
  b:=c         ;
end;
writeln(g,a);
end;
close(f);
close(g);
end.
