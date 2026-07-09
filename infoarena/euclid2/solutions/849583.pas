Var f,g:text;
    a,b,n,i,r:longint;

Begin
assign(f, 'euclid2.in');reset(f);
assign(g, 'euclid2.out');rewrite(g);
read(f, n);
for i:=1 to n do
  begin
    read(f, a,b);
    r:=1;
    while r<>0 do
      begin
        r:=a mod b;
        a:=b;
        b:=r;
      end;
    writeln(g, a);
  end;
close(f);
close(g);
End.