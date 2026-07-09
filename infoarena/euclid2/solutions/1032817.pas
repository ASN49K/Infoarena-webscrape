var a,b,n,i,c,aux:integer;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do
  begin
    readln(f,a,b);
    while a mod b<>0 do
      begin
          if a mod b<>0 then
            begin
              aux:=a;
              a:=b;
              b:=aux mod b;
            end;
      end;
    if a mod b=0 then c:=b;
    writeln(g,c);
  end;
close(f);close(g);
end.