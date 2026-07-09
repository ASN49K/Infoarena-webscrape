var r,d,i,j,t,a,b:longint;
    fin,fout:text;
begin
assign(fin,'euclid2.in');reset(fin);assign(fout,'euclid2.out');rewrite(fout);
readln(fin,t);
if t<1 then t:=1 else if t>100000 then t:=100000;
i:=1;
while i<=t do begin
  read(fin,a);
  readln(fin,b);
 if (a<2)OR(b>2000000000) then begin
  read(fin,a);
  readln(fin,b); inc(i); end;
 if b<0 then b:=abs(b);
 {if a>=b then min:=b else min:=a;

 for j:=min downto 1 do
  if (a mod j=0)AND(b mod j=0) then begin d:=abs(j);
 break; end;}
 while a mod b<>0 do begin
  r:=a mod b;
  a:=b;
  b:=r;
  end; d:=b;
 writeln(fout,d);  inc(i);
 end;
close(fin);close(fout);
end.

