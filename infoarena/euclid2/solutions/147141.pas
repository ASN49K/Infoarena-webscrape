program euclid;
var f,g:text;
    a,b:longint;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,a,b);
while a<>b do begin
      if a>b then a:=a-b
             else b:=b-a;
      end;
writeln(g,a);
close(g);
end.