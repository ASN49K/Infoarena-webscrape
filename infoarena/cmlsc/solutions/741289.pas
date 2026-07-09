var t:array[0..1024,0..1024] of word;
    i,j,n,m,mx:integer;
    x,y:array[1..1024] of byte;

Function max(a,b:word):word;
Begin
if a>b then max:=a else max:=b;
End;

BEGIN
  assign(input,'cmlsc.in');
  reset(input);
  readln(n,m);
  for i:=1 to n do
    read(x[i]);
  readln;
  for i:=1 to m do
    read(y[i]);
  close(input);
  for i:=1 to n do
    t[i,0]:=0;
  for j:=1 to m do
    t[0,j]:=0;
  for i:=1 to n do
    for j:=1 to m do
      if x[i]=y[j]
        then
          t[i,j]:=t[i-1,j-1]+1
        else
          t[i,j]:=max(t[i,j-1],t[i-1,j]);
  assign(output,'cmlsc.out');
  rewrite(output);
  writeln(t[n,m]);
  mx:=1;
  for i:=1 to n do
    for j:=1 to m do
      if t[i,j]=mx then
        if x[i]=y[j] then
          begin
            write(x[i],' ');
            mx:=mx+1;
          end;
  close(output);
END.
