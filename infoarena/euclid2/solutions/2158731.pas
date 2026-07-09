var n,a,b,i : longint ;
    f,g : text;
begin
  assign(f,'euclid2.in');reset(f);
  assign(g,'euclid2.out');rewrite(g);
  read(f,n);
  for i:=1 to n do
  begin
  read(f,a,b);
    while b <>0 do
    begin
      b:=(b mod a)+a;
      a:=b-a;
      b:=b-a;
    end;
  writeln(g,a);
  end;
  close(f);
  close(g);
end.