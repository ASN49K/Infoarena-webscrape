program euclid;
var f,g:text;
    a,b,r,i,t:longint;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,t);
for i:=1 to t do begin
readln(f,a,b);
while b>0 do begin
      r:=a mod b;
      a:=b;
      b:=r;
      end;
writeln(g,a);
end;
close(g);
end.