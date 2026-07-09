program joc_nim;
var t,i,nrp,x,y:word;
    f,g:text;
begin
assign(f,'nim.in');reset(f);
assign(g,'nim.out');rewrite(g);
readln(f,t);
while t>0 do
 begin
 readln(f,nrp); x:=0;
 for i:=1 to nrp do begin
                    read(f,y);
                    x:=x xor y;
                    end;
 if x>0 then writeln(g,'DA')
        else writeln(g,'NU');
 dec(t);
 end;
close(f); close(g);
end.