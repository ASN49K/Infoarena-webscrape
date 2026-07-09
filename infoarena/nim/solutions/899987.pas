program joc_nim;
type vect=array[1..10000]of word;
var v:vect; t,i,nrp,k,x:word; ok:boolean;
    f,g:text;
begin
assign(f,'nim.in');reset(f);
assign(g,'nim.out');rewrite(g);
readln(f,t);
for k:=1 to t do
 begin
 readln(f,nrp);
 ok:=true;
 for i:=1 to nrp do begin
                    read(f,x);
                    if (i mod 2=1)then if x=1 then ok:=false;
                    end;
 if ok then writeln(g,'DA')
       else writeln(g,'NU');
 end;
close(f); close(g);
end.