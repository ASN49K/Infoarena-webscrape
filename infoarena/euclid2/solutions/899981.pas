var f,g:text;
    a,b,c,n,i,aux:longint;
begin
 assign(f,'euclid2.in');reset(f);
 assign(g,'euclid2.out');rewrite(g);
 read(f,n);
 for i:=1 to n do
 begin
   read(f,a,b);c:=a mod b;
   while c<>0 do
   begin
    a:=b;
    b:=c;
    c:= a mod b;
   end;
   writeln(g,b);
 end;
close(f);close(g);
end.
