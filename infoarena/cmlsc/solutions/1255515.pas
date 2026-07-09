program p2;
function max(a,b:integer):byte;
  begin
  if a>b then max:=a
            else max:=b;
  end;
  var fi,fo:text;
      a,b:array[1..1200] of byte;
      c:array[1..1200,1..1200] of byte;
      n,m,i,j,maxi,piv:integer;
Begin
  assign(fi,'cmlsc.in');reset(fi);
  assign(fo,'cmlsc.out');rewrite(fo);
  readln(fi,n,m);
  for i:=2 to n+1 do read(fi,a[i]);
  for i:=2 to m+1 do read(fi,b[i]);
  {for i:=2 to n+1 do write(fo,a[i],' ');writeln(fo);
  for j:=2 to m+1 do write(fo,b[j],' ');}
  piv:=0;
  for i:=2 to n+1 do
   for j:=2 to m+1 do
    if (a[i]=b[j]) then begin
                         inc(piv);
                         c[i,j]:=piv;
                         end
       else c[i,j]:=max(c[i,j-1],c[i-1,j]);
  {for i:=2 to n+1 do begin
    for j:=2 to m+1 do write(fo,c[i,j],' ');
    writeln(fo);
                   end;}
  writeln(fo,c[n+1,m+1]);
  i:=2;j:=2;maxi:=0;
  {while (i<=n+1) do begin
    while (j<=m+1) do
    if (a[i]=b[j]) then begin
                         write(fo,a[i],' ');
                         inc(i);
                         j:=2;
                         end
               else inc(j);
    inc(i); j:=2;
                     end;}
  while (i<=n+1) do begin
    while (j<=m+1) do
      if c[i,j]>maxi then begin
                          write(fo,a[i],' ');
                          maxi:=c[i,j];
                          inc(i);
                          j:=2;
                          end
                     else inc(j);
      inc(i);j:=2;
                     end;
  close(fi);
  close(fo);
end.
