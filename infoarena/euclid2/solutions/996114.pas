var a,b,t,i,r:longint; f,g:text;
begin
 assign(f,'euclid2.in'); reset(f);
 assign(g,'euclid2.out');  rewrite(g);
 readln(f,t);
 for i:=1 to t do begin
  readln(f,a,b);
  while b<>0 do begin
    r:=a mod b;
    a:=b;
    b:=r;
   end;
  writeln(g,a);
 end;
 close(f); close(g);
end.
