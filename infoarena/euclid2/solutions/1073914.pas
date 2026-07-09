var t,i:longint;
    a,b,c:array[1..100000] of longint;

begin
  assign(input,'euclid2.in');
  assign(output,'euclid2.out');
  reset(input);
  rewrite(output);

  read(t);
  for i:=1 to t do begin
    read(a[i]);
    read(b[i]);
    while a[i]>0 do begin
      c[i]:=b[i] mod a[i];
      b[i]:=a[i];
      a[i]:=c[i];
    end;
    writeln(b[i]);
  end;
end.