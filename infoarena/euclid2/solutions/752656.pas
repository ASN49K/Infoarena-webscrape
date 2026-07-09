program algortim;
var f,g:text;
    t:longint;
    x,y,r,i,aux:longint;
begin
assign(f,'euclid2.in');reset(f);readln(f,t);
assign(g,'euclid2.out');rewrite(g);
r:=0;
for i:=1 to t do begin
                 readln(f,x,y);
                 if x<y then begin
                             aux:=x;x:=y;y:=aux;
                             end;
                 r:=x mod y;
                 while r<>0 do begin
                               x:=y;
                               y:=r;
                               r:=x mod y;
                               end;
                 writeln(g,y);
                 end;
close(f);close(g);
end.
