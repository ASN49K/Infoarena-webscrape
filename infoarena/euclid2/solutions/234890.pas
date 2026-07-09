program alex;
var f,g:text;
    n,a,b,r,i:longint;
begin
assign(f,'euclid2.in');reset(f);
readln(f,n);
assign(g,'euclid2.out');rewrite(g);
for i:=1 to n do
    begin
    readln(f,a,b);
    r:=a mod b;
    while r<>0 do
          begin
          a:=b;
          b:=r;
          r:=a mod b;
          end;
    writeln(g,b);
    end;
close(f);
close(g);
end.