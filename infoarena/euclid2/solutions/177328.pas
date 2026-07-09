var fin,fout:text;
    t,i,a,b,r,r2:longint;
begin
assign(fin,'euclid2.in');reset(fin);
assign(fout,'euclid2.out');rewrite(fout);
readln(fin,t);
for i:=1 to t do
    begin
    r:=0;r2:=0;
    read(fin,a,b);
    r:=a mod b;
    if r=0 then writeln(fout,b)
           else  begin
          while r<>0 do
          begin
          a:=b;b:=r;r2:=r;
          r:=a mod b;
          end;
    writeln(fout,r2); end;
    readln(fin);
    end;
close(fin);close(fout);
end.

