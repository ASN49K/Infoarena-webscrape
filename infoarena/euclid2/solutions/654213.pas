program euclid;
  var fi,fo:text;
      a,b,n,i:longint;
begin
  assign(fi,'euclid2.in');
  reset(fi);
  readln(fi,n);
  assign(fo,'euclid2.out');
  rewrite(fo);
  for i:=1 to n do
    begin
      readln(fi,a,b);
      while (a<>0) and (b<>0) do
          if a>b then a:=a mod b else b:=b mod a;
      if a=0 then writeln(fo,b) else writeln(fo,a);
    end;
  close(fi);
  close(fo);
end.