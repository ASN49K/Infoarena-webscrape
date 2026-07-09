program euclid;
 var a,b,i,t,r:longint;
     f,g:text;
Begin
 Assign(f,'euclid2.in');reset(f);
 Assign(g,'euclid2.out');rewrite(g);
 readln(f,t);
 for i:=1 to t do begin
  read(f,a);readln(f,b);
  r:=1;
  while r<>0 do begin
   r:=a mod b;
   a:=b;
   b:=r;
  end;
  writeln(g,a);
 end;
 close(g);close(f);
end.