program euclid;
 var a,b,i,t,r:longint;
     f,g:text;
Begin
 Assign(f,'euclid.in');reset(f);
 Assign(g,'euclid.out');rewrite(g);
 readln(f,t);
 for i:=1 to t do begin
  read(f,a);readln(f,b);
  while b<>0 do begin
   r:=a mod b;
   a:=b;
   b:=r;
  end;
  writeln(g,a);
 end;
 close(g);close(f);
end.