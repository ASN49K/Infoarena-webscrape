var n,m,i,j,k,r:longint;
    a,b,c:array[1..1025] of longint;
    t:array[1..1025,1..1025] of longint;

function max(a,b:longint):longint;
begin
  if a>b then max:=a
  else max:=b;
end;

begin
  assign(input,'cmlsc.in');
  assign(output,'cmlsc.out');
  reset(input);
  rewrite(output);
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  for i:=2 to n+1 do
    for j:=2 to m+1 do begin
      if a[i-1]=b[j-1] then
        t[i,j]:=t[i-1,j-1]+1
      else t[i,j]:=max(t[i,j-1],t[i-1,j]);
    end;
  k:=t[i,j];
  r:=k;
  writeln(k);
  while (i>1) and (j>1) do begin
    if a[i-1]=b[j-1] then begin
      c[k]:=a[i-1];
      dec(k);
      dec(i);
      dec(j);
    end else begin
      if t[i-1,j]>t[i,j-1] then dec(i)
      else dec(j);
    end;
  end;
  for i:=1 to r do
    write(c[i],' ');
end.