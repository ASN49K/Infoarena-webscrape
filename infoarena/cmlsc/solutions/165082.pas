var f,g:text;
    n,m,i,j,k:integer;
    c:array[0..1024,0..1024] of byte;
    a,b,d:array[1..1024] of byte;

procedure citire;
  begin
    assign(f,'cmlsc.in');
    reset(f);
    readln(f,n,m);
    for j:=1 to n do read(f,a[j]);
    readln(f);
    for i:=1 to m do read(f,b[i]);
    readln(f);
    close(f);
  end;

procedure cmlsc;
  begin
    for i:=1 to n do
      for j:=1 to m do
        if a[i]=b[j] then
          c[i,j]:=c[i-1,j-1]+1
        else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j]
             else c[i,j]:=c[i,j-1];
  end;

procedure afisare;
  begin
    assign(g,'cmlsc.out');
    rewrite(g);
    writeln(g,c[n,m]);
    k:=0;
    i:=n;
    j:=m;
    while c[i,j]<>0 do
      if a[i]=b[j] then begin
        inc(k);
        d[k]:=a[i];
        dec(i);
        dec(j);
      end
      else if c[i,j]=c[i-1,j] then dec(i) else dec(j);
    for i:=k downto 1 do write(g,d[i],' ');
    close(g);
  end;

begin
  citire;
  cmlsc;
  afisare;
end.
