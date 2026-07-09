function euclid(x,y:longint):longint;
begin
if y=0 then euclid:=x
else euclid:=euclid(y,x mod y)
end;
var f,g:Text;
i,n,m,x:longint;
begin
assign(F,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
i:=0;  readln(f);
while (not eof(f)) do begin
read(f,n,m);
writeln(g,euclid(n,m));
inc(i)
end;
close(g)
end.

