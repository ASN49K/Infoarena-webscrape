program p2;
function max(a,b:longint):longint;
  begin
  if a>b then max:=a
            else max:=b;
  end;
  var fi,fo:text;
      a,b:array[1..1200] of longint;
      c:array[1..1200,1..1200] of longint;
      n,m,i,j,maxi,piv,min,k,i1:longint;
Begin
  assign(fi,'cmlsc.in');reset(fi);
  assign(fo,'cmlsc.out');rewrite(fo);
  readln(fi,n,m);
  for i:=2 to n+1 do read(fi,a[i]);
  for i:=2 to m+1 do read(fi,b[i]);
  {for i:=2 to n+1 do write(fo,a[i],' ');writeln(fo);
  for j:=2 to m+1 do write(fo,b[j],' ');}
  for i:=2 to n+1 do
   for j:=2 to m+1 do
    if (a[i]=b[j])and(c[i-1,j]=c[i,j-1]) then c[i,j]:=c[i-1,j]+1
       else c[i,j]:=max(c[i,j-1],c[i-1,j]);
  for i:=2 to n+1 do begin
    for j:=2 to m+1 do write(fo,c[i,j],' ');
    writeln(fo);
                   end;
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
  {while (i<=n+1) do begin
    while (j<=m+1) do
      if c[i,j]>maxi then begin
                          write(fo,a[i],' ');
                          maxi:=c[i,j];
                          inc(i);
                          j:=2;
                          end
                     else inc(j);
      inc(i);j:=2;
                     end;}
  piv:=0;i:=2; j:=2; min:=n*m; k:=c[n+1,m+1];
  while (k<>0) do begin
   j:=2; i:=2; min:=n*m;
   while (j<=n+1) do begin
    if (c[i,j]>piv)and(i+j<=min) then begin
                         min:=i+j;
                         i1:=i;
                        end;
     inc(i);
     if i>n+1 then begin
                   inc(j);
                   i:=2;
                 end;
                   end;
    write(fo,a[i1],' ');
    k:=k-1;
    inc(piv);
                   end;

  close(fi);
  close(fo);
end.
