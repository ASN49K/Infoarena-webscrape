program p9;
  var fi,fo:text;
      n,m,i,t,r:longint;
Begin
  assign(fi,'euclid2.in');reset(fi);
  assign(fo,'euclid2.out');rewrite(fo);
  readln(fi,t);
  for i:=1 to t do begin
   readln(fi,n,m);
   r:=n mod m;
   while r<>0 do begin
                 n:=m;
                 m:=r;
                 r:=n mod m;
                end;
   writeln(fo,m);
                   end;
   close(fi);
   close(fo);
end.