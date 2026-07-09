uses math;
var a,b,v:array[1..1025] of byte;
    d:array[0..1025,0..1025] of byte;
    i,j,n,m,k:integer;
    f,g:text;
begin
  assign(f,'cmlsc.in'); reset(f);
  assign(g,'cmlsc.out'); rewrite(g);
  readln(f,m,n);

  for i:=1 to m do read(f,a[i]);
  for i:=1 to n do read(f,b[i]);

  for i:=1 to m do
      for j:=1 to n do
          if a[i]=b[j] then d[i,j]:=d[i-1,j-1]+1
                       else d[i,j]:=max(d[i-1,j],d[i,j-1]);
  writeln(g,d[m,n]);

  while k<>d[m,n] do
       begin
         if a[i]=b[j] then begin
                           inc(k);
                           v[k]:=a[i];
                           end
                      else
            if d[i-1,j]>d[i,j-1] then inc(j)
                                 else inc(i);
         dec(i);
         dec(j);
       end;

  for i:=k downto 1 do write(g,v[i], ' ');
  close(g);
end.