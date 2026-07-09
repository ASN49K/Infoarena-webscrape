var x,y,aux,gcd,i,t:integer;
    k:boolean;
    f,g:text;

begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f,T);
for i:=1 to T do begin
 readln(f,x,y);
 if x<y then begin
               aux:=x;
               x:=y;
               y:=aux;
             end;
 if x mod y=0 then gcd:=y
              else gcd:=x mod y;

 repeat
 k:=true;
 if (x mod gcd=0) and (y mod gcd=0) then writeln(g,gcd)
                                    else begin gcd:=x mod gcd; k:=false;end;
 until k=true;
 writeln(g,gcd);
 end;
 close(f);
 close(g);
end.