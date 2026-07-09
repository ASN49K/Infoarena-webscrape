var a,b,r,T,i:longint;   F,G:text;
begin
  assign(F, 'euclid2.in'); reset(F);
  assign(G, 'euclid2.out'); rewrite(G);
  for i:=1 to T do begin
   readln(F,a,b);
    while b<>0 do begin
     r:=a mod b;
     a:=b;
     b:=r;
    end;
  writeln(G, a);
 end;
close(F);
close(G);
end.


