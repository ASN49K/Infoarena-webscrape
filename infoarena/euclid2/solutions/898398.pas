var f,g:text;
    a,b,c,n,i:longint;
begin
 assign(f,'euclid.in');reset(f);
 assign(g,'euclid.out');rewrite(g);
 read(f,n);
 for i:=1 to n do
 begin
 read(f,a,b);
 while a mod b<>0 do
  begin
   c:=a mod b;
   a:=b;
   b:=c;
  end;
writeln(g,b);
end;
close(f);close(g);
end.
