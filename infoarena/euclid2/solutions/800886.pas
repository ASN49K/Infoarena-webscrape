var f,g:text;
    a,b,t,i,aux,r:longint;
    b1,b2:array[1..650] of longword;
begin
  assign(f,'euclid2.in');
  assign(g,'euclid2.out');
  settextbuf(f,b1);
  settextbuf(g,b2);
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
