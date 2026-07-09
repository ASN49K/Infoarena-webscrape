program subsir;
  var f:text;
      m,n,i,k,j:integer;
      a,b,t:array [1..1024] of byte;
      c: array [0..1024,0..1024] of integer;
begin
  assign(f,'cmlsc.in');
  reset(f);
  readln(f,m,n);
  for i:=1 to m do read(f,a[i]);
  readln(f);
  for i:=1 to n do read(f,b[i]);
  close(f);
  assign(f,'cmlsc.out');
  rewrite(f);
  for i:=0 to m do c[i,0]:=0;
  for i:=0 to n do c[0,i]:=0;
  k:=0;
  for i:=1 to m do
    for j:= 1 to n do
      if a[i]=b[j] then begin
                          c[i,j]:=c[i-1,j-1]+1;
                          k:=k+1;
                          t[k]:=a[i];
                        end
                   else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j]
                                             else c[i,j]:=c[i,j-1];

  writeln(f,c[m,n]);
  for i:=1 to c[m,n] do write(f,t[i],' ');
  close(f);
end.