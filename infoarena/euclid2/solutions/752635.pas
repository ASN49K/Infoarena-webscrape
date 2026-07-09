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
                 repeat
                 r:=x mod y;x:=y;y:=r;
                 until r=0;
                 writeln(g,x);
                 end;
close(f);close(g);
end.
