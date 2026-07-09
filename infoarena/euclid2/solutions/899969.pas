var f,g:text;
    a,b,c,n,i,aux:longint;
begin
 assign(f,'euclid2.in');reset(f);
 assign(g,'euclid2.out');rewrite(g);
 read(f,n);
 for i:=1 to n do
 begin
   read(f,a,b);c:=a mod b;
   if a<b then begin
                        aux:=a;
                        a:=b;
                        b:=aux;
                        end;
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
