var a,b,t:longint;
    f:text;

begin
  assign(f,'euclid2.in');
  reset(f);
  read(f,a,b);
  close(f);
  while b>0 do
    begin
      t:=a mod b;
      a:=b;
      b:=t;
    end;
  assign(f,'euclid2.out');
  rewrite(f);
  write(f,a);
  close(f);
end.
