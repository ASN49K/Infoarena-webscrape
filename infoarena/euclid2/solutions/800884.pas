var f,g:text;
    a,b,t,i,aux,r:longint;
begin
  assign(f,'euclid2.in');
  assign(g,'euclid2.out');
  reset(f);
  rewrite(g);
  readln(f,t);
  for i:=1 to t do
    begin
      readln(f,a,b);
      if a<b then
        begin
          aux:=a;
          a:=b;
          b:=aux;
        end;
      repeat
        r:=a mod b;
        a:=b;
        b:=r;
      until r=0;
      writeln(g,a);
    end;
  close(f);
  close(g);
end.
