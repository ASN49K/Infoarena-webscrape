var f,g:text;
    x,n,m,i,j,min,nr:longint;
    fr1,fr2:array[0..1000] of longint;
begin
  assign(f,'cmlsc.in'); reset(f);
  assign(g,'cmlsc.out'); rewrite(g);
  read(f,n,m);
  for i:=1 to n do
    begin
      read(f,x);
      inc(fr1[x]);
    end;
  for i:=1 to m do
    begin
      read(f,x);
      inc(fr2[x]);
    end;
  nr:=0;
  for i:=0 to 256 do
    if (fr1[i]>0) and (fr2[i]>0) then inc(nr);
  writeln(g,nr);
  for i:=0 to 256 do
    begin
      min:=fr1[i];
      if fr2[i]<min then min:=fr2[i];
      for j:=1 to min do write(g,i,' ');
    end;
  writeln(g);
  close(f); close(g);
end.