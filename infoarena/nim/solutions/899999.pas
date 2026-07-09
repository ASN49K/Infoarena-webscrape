program joc_nim;
type vect=array[1..10000]of word;
var v:vect; t,i,nrp,k,x,y:word; ok:boolean;
    f,g:text;
begin
assign(f,'nim.in');reset(f);
assign(g,'nim.out');rewrite(g);
readln(f,t);
for k:=1 to t do
 begin
 readln(f,nrp); x:=0;
 for i:=1 to nrp do begin
                    read(f,y);
                    x:=x xor y;
                    end;
 if x>0 then writeln(g,'DA')
        else writeln(g,'NU');
 end;
close(f); close(g);
end.