var f,g:text;
    a1,a2,r:longint;
begin
  assign(f,'euclid2.in'); reset(f);
  assign(g,'euclid2.out'); rewrite(g);
  read(f,a1,a2);
  while a2<>0 do
    begin
      r:=a1 mod a2;
      a1:=a2;
      a2:=r;
    end;
  writeln(g,a1);
  close(f); close(g);
end.