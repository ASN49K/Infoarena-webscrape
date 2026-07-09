var f,g:text;
    a,b,c,n,i:longint;
begin
 assign(f,'euclid.in');reset(f);
 assign(g,'euclid.out');rewrite(g);
 read(f,n);
 for i:=1 to n do
 begin
   read(f,a,b);
   while b<>0 do
   begin
    c:=b;
    b:=a mod c;
    a:=c;
   end;
   writeln(g,a);
 end;
close(f);close(g);
end.
