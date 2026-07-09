var f,g:text;
    t,i,a,b,aux:longword;
begin
  assign (f,'euclid2.in');reset (f);
  assign (g,'euclid2.out');rewrite (g);
  readln (f,t);
  for i:=1 to t do
  begin
    readln (f,a,b);
    if a<b then
    begin
      aux:=a;
      a:=b;
      b:=aux
    end;
    while b<>0 do
    begin
      aux:=b;
      b:=a mod b;
      a:=aux
    end;
    writeln (g,a)
  end;
  close (f);close (g)
end.
