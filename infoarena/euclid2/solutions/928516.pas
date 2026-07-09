var
i,j,k,l,m,n:longint;
ini,ou:text;
begin
 assign(ini,'euclid2.in');
 reset(ini);
 assign(ou,'euclid2.out');
 rewrite(ou);
 read(ini,n);
  for i:=1 to n do
  begin
  readln(ini,l,m);
  if l<m then begin k:=l; l:=m; m:=k; end;
   repeat
   k:=l mod m;
   l:=m;
   m:=k;
   until m=0;
  writeln(ou,l);
  end;
 close(ou);
 close(ini);
end.