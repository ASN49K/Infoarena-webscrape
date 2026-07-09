var a,b,r:longint;
    f:text;
begin
   assign(f,'euclid2.in');
   reset(f);
   read(f,a,b);
   close(f);
   if a<b then begin r:=a;
                     a:=b;
                     b:=r;
               end;
   while a mod b>0 do
   begin
   r:=a mod b;
   a:=b;
   b:=r;
   end;
   assign(f,'euclid2.out');
   rewrite(f);
   writeln(f,b);
   close(f);
end.
