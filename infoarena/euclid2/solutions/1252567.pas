program p9;
  var fi,fo:text;
      n,m,i,t:integer;
Begin
  assign(fi,'euclid2.in');reset(fi);
  assign(fo,'euclid2.out');rewrite(fo);
  readln(fi,t);
  for i:=1 to t do begin
  readln(fi,n,m);
  if n=m then writeln(fo,n) else
    while (abs(n)>0)and(abs(m)>0) do
      if n>m then n:=n-m
             else m:=m-n;
      if n=0 then writeln(fo,m) else
        if m=0 then writeln(fo,n);
                    end;
  close(fi);
  close(fo);
end.
