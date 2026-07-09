var a,b,x,t,i:longint;
f,g:text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);rewrite(g);
readln(f,t);
for i:=1 to t do
    begin
    readln(f,a,b);
    while b<>0 do
          begin
          x:=a;
          a:=b;
          b:=x mod b;
          end;
    writeln(g,a);
    end;
close(f);close(g);
end.