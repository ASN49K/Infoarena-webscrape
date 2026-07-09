var a,b:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f);
while not eof(f) do begin
  readln(f,a,b);
  while (a>0)and(b>0) do begin
       if a>=b then begin
                     a:=a mod b;
                    end
               else begin
                     b:=b mod a;
                    end;
                         end;
if a=0 then writeln(g,b)
       else writeln(g,a);
                    end;
close(f);close(g);
end.
