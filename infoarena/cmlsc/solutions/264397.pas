var f,g:text;
    n,m,i,j,k:integer;
    a,b:array[1..1024] of byte;
    c:array[0..1024,0..1024] of byte;

procedure subsir;
  begin
    if a[i]=b[j] then begin k:=k+1; i:=i-1; j:=j-1; subsir;  write(g,a[i],' '); end
      else if c[i-1,j]<c[i,j-1] then begin
        j:=j-1 end else begin i:=i-1; subsir; end;
  end;

begin
  assign(f,'cmlsc.in');
  reset(f);
  assign(g,'cmlsc.out');
  rewrite(g);
  readln(f,n,m);
  for i:=1 to n do read(f,a[i]);
  readln(f);
  for i:=1 to m do read(f,b[i]);
  close(f);
  for i:=1 to n do
    for j:=1 to m do if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
      else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j] else
        c[i,j]:=c[i,j-1];
  writeln(g,c[n,m]);
  close(g);
end.


