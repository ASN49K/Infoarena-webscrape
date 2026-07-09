var a,b,t,test,i:longint;
    f,g:text;

begin
  assign(f,'euclid2.in');
  reset(f);
  assign(g,'euclid2.out');
  rewrite(g);
  readln(f,test);
  for i:=1 to test do
    begin
      readln(f,a,b);
      while b>0 do
        begin
          t:=a mod b;
          a:=b;
          b:=t;
        end;
      writeln(g,a);
    end;
  close(f);
  close(g);
end.
