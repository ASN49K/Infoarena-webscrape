var t:array[0..1024,0..1024] of word;
    i,j,n,m,mx:integer;
    x,y,s:array[1..1024] of byte;

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
  mx:=0;
  i:=n;
  j:=m;
  while (i>0) and (j>0) do
    if x[i]=y[j]
      then
        begin
          mx:=mx+1;
          s[mx]:=x[i];
          i:=i-1;
          j:=j-1;
        end
      else
        if x[i,j-1]>x[i-1,j]
          then
            j:=j-1
          else
            i:=i-1;
for i:=1 to mx do
write(s[i],' ');
close(output);
END.
