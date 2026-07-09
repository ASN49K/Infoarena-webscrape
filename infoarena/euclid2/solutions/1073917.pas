var t,i,a,b,c:longint;

begin
  assign(input,'euclid2.in');
  assign(output,'euclid2.out');
  reset(input);
  rewrite(output);

  read(t);
  for i:=1 to t do begin
    read(a);
    read(b);
    while a>0 do begin
      c:=b mod a;
      b:=a;
      a:=c;
    end;
    writeln(b);
  end;
end.