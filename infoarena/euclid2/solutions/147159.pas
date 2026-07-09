program euclid;
var f,g:text;
    a,b,r:longint;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,a,b);
while b>0 do begin
      r:=a mod b;
      a:=b;
      b:=r;
      end;
writeln(g,a);
close(g);
end.