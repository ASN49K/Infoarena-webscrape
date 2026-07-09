const nmax=1024;
var fi,fo:text;
    A,B,drum:Array[0..nmax]of byte;
    dr:Array[0..nmax,0..nmax]of byte;
    ct:Array[0..nmax,0..nmax]of integer;
    m,n,i,j,cont:integer;

procedure readd;
begin
  assign(fi,'cmlsc.in'); reset(fi);

  read(fi,n,m);
  for i:=1 to n do
    read(fi,A[i]);
  for i:=1 to m do
    read(fi,B[i]);
  close(fi);
end;

procedure compute(i,j:integer);
begin
  while dr[i,j]<>0 do
   begin
    if A[i]=B[j] then
      begin
        inc(cont);
        drum[cont]:=A[i];
      end;
    if dr[i,j]=1 then
      begin
      i:=i-1;
      j:=j-1;
      end
    else
     if dr[i,j]=2 then i:=i-1
      else j:=j-1;
   end;
end;

procedure print;
begin
  assign(fo,'cmlsc.out'); rewrite(fo);
  writeln(fo,ct[n,m]);
  for i:=cont downto 1 do
    write(fo,drum[i],' ');
  close(fo);
end;

procedure solve;
begin
  for i:=1 to n do
    for j:=1 to m do
      if A[i]=B[j] then
        begin
          ct[i,j]:=ct[i-1,j-1]+1;
          dr[i,j]:=1;
        end
      else
        begin
          ct[i,j]:=ct[i-1,j];
          dr[i,j]:=2;
          if ct[i,j]<ct[i,j-1] then
            begin
              ct[i,j]:=ct[i,j-1];
              dr[i,j]:=3;
            end;
        end;
  compute(n,m);
  print;
end;

begin
  readd;
  solve;
end.
