program p9;
  var fi,fo:text;
      n,m,i,t:longint;
Begin
  assign(fi,'euclid.in');reset(fi);
  assign(fo,'euclid.out');rewrite(fo);
  readln(fi,t);
  for i:=1 to t do begin
  readln(fi,n,m);
  if n=m then writeln(fo,n) else
    while (n>0)and(m>0) do
      if n>m then n:=n-m
             else m:=m-n;
      if n=0 then writeln(fo,m) else
        if m=0 then writeln(fo,n);
                    end;
  close(fi);
  close(fo);
end.
