program p2;
function max(a,b:integer):byte;
  begin
  if a>b then max:=a
            else max:=b;
  end;
  var fi,fo:text;
      a,b:array[1..1200] of byte;
      c:array[1..1200,1..1200] of byte;
      n,m,i,j:integer;
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
    if (a[i]=b[j]) then c[i,j]:=c[i,j-1]+1
       else c[i,j]:=max(c[i,j-1],c[i-1,j]);
  for i:=2 to n+1 do begin
    for j:=2 to m+1 do write(fo,c[i,j],' ');
    writeln(fo);
                   end;
  close(fi);
  close(fo);
end.
