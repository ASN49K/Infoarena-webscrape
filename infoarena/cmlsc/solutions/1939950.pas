program cmlsc;
  var m,n,c,i,j:word;
      a,b,sir:array[1..1024] of word;
      d:array[0..1024,0..1024] of word;
      fi,fo:text;
begin  assign(fi,'cmlsc.in'); assign(fo,'cmlsc.out'); reset(fi); rewrite(fo);
  read(fi,m); readln(fi,n);

  for i:=1 to m-1 do read(fi,a[i]);
  readln(fi,a[m]);

  for i:=1 to n do read(fi,b[i]);
  close(fi);

  for i:=0 to m do
    for j:=0 to n do d[i,j]:=0;

   for i:=1 to m do
    for j:=1 to n do
      if a[i]=b[j] then d[i,j]:=d[i-1,j-1]+1
             else if d[i-1,j]>d[i,j-1] then d[i,j]:=d[i-1,j] else d[i,j] :=d[i,j-1];


  c:=1;
    for i:=1 to m do
    for j:=1 to n do
      if d[i,j]=c then begin inc(c);  sir[c]:=a[i];  end;

  writeln(fo,c);
  for i:=2 to c-1 do write(fo,sir[i],' '); write(fo,sir[c]);
  close(fo);

  end.


