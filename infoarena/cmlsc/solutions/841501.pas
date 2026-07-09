program cmlsc;
  var f:text;
      a,b:array [1..1024] of integer;
      m,n,i,j:integer;
      tab:array [1..1025,1..1025] of integer;
begin
  assign(f,'cmlsc.in');
  reset(f);
  readln(f,m,n);
  for i:=1 to m do read(f,a[i]); readln(f);
  for i:=1 to n do read(f,b[i]);
  for i:=m downto 1 do
    for j:=n downto 1 do
      if a[i]=b[j] then tab[i,j]:=tab[i+1,j+1]+1
                   else if tab[i,j+1]>tab[i+1,j] then tab[i,j]:=tab[i,j+1]
                                                 else tab[i,j]:=tab[i+1,j];
  close(f);
  assign(f,'cmlsc.out');
  rewrite(f);
  writeln(f,tab[1,1]);
  i:=1; j:=1;
  while tab[i,j]<>0 do
    begin
      if tab[i+1,j+1]=tab[i,j] then begin inc(i);inc(j);end
         else if tab[i+1,j]=tab[i,j] then inc(i)
              else if tab[i,j+1]=tab[i,j] then inc(j)
                   else begin write(f,a[i],' '); inc(i); inc(j); end;
    end;
  close(f);
end.
    end;
