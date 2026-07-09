program p3;
function max(a,b:longint):longint;
  begin
  if a>b then max:=a
            else max:=b;
  end;
  var fi,fo:text;
      a,b,d:array[1..1200] of longint;
      c:array[1..1200,1..1200] of longint;
      i,j,n,m,k:longint;
Begin
  assign(fi,'cmlsc.in');reset(fi);
  assign(fo,'cmlsc.out');rewrite(fo);
  readln(fi,n,m);
  for i:=2 to n+1 do read(fi,a[i]);
  for i:=2 to m+1 do read(fi,b[i]);
  for i:=2 to n+1 do
    for j:=2 to m+1 do
      if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
        else c[i,j]:=max(c[i,j-1],c[i-1,j]);
  writeln(fo,c[n+1,m+1]);
  j:=m+1;i:=n+1; k:=0;
  while (i>=2) do begin
    while (j>=2) do begin
      if a[i]=b[j] then begin
                          inc(k);
                          d[k]:=a[i];
                          dec(i);
                          dec(j);
                        end;
      dec(j);
                     end;
    j:=m+1;
    dec(i);
                  end;
  for i:=k downto 1 do write(fo,d[i],' ');
  close(fi);
  close(fo);
end.
