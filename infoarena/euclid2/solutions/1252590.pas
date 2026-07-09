program p9;
  var fi,fo:text;
      n,m,i,t,r:longint;
Begin
  assign(fi,'euclid2.in');reset(fi);
  assign(fo,'euclid2.out');rewrite(fo);
  readln(fi,t);
  for i:=1 to t do begin
   readln(fi,n,m);
   while m<>0 do begin
                 r:=n mod m;
                 n:=m;
                 m:=r;
                end;
   writeln(fo,n);
                   end;
   close(fi);
   close(fo);
end.
