var f,g:text;t,i,a,b:longint;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);read(f,t);
for i:=1 to t do begin
readln(f,a,b);
repeat
c:=a div b;
r:= a mod b;
a:=b; b:=r;
until r=0;
writeln(g,a);  end;
end.
