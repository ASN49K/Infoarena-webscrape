var a,b,n,i,aux:longint;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do
  begin
    readln(f,a,b);
    while a mod b <>0 do
      begin
        aux:=a;
        a:=b;
        b:=aux mod b;
      end;
    writeln(g,b);
  end;
close(f);close(g);
end.