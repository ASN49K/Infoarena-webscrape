type  mat=array[1..1024,1..1024] of integer;
      vek=array[1..1024] of integer;
var n,m,i,j,i1,j1,d,k,l,c:integer; f:text; a,b,q:vek; x:mat;
function max(r,t:integer):integer;
  var i,j,mx:integer;
  begin
    mx:=-1;
    for i:=1 to r do
      for j:=1 to t do
        if x[i,j]>mx then begin mx:=x[i,j]; i1:=i;j1:=j; end;
    max:=mx;
  end;
begin
  assign(f,'cmlsc.in');
  reset(f);
  readln(f,m,n);
  for i:=1 to m do
    read(f,a[i]);
  readln(f);
  for i:=1 to n do
    read(f,b[i]);
  close(f);
  for i:=1 to n do begin
    for j:=1 to m do
      if a[j]=b[i] then if (i>1) and (j>1) then begin x[i,j]:=max(i-1,j-1)+1; if x[i,j]>d then d:=x[i,j]; end
                                         else begin x[i,j]:=1; d:=1; end;
    end;
   k:=n; l:=m;
  repeat
    max(k,l);
    inc(c); q[c]:=a[j1];
    k:=i1-1; l:=j1-1;
  until (k<=1) or (j<=1);
  assign(f,'cmlsc.out');
  rewrite(f);
  writeln(f,d);
  for i:=c downto 1 do
  write(f,q[i],' ');
  close(f);
end.
