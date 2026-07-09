var a,b,n,i,aux:longint;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do
  begin
    readln(f,a,b);
    repeat
      if a mod b<>0 then
        begin
          aux:=a;
          a:=b;
          b:=aux mod b;
        end;
      if a mod b=0 then writeln(g,b);
    until a mod b=0;
  end;
close(f);close(g);
end.