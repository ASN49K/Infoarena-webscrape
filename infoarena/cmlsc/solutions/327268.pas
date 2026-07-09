program cmlsc;
 var a,b:text;
  i,j,k,x,y,xk,yk:integer;
  z:array[-1..1024,-1..1024] of byte;
  xx:array[1..1024] of byte;
  function max(i,j:byte):byte;
   begin
   if i>j then max:=i else max:=j;
   end;
  begin
   assign(a,'cmlsc/grader_test2.in');
   assign(b,'cmlsc.out');
   reset(a);
   rewrite(b);
   Readln(a,x,y);
   for i:=1 to x do
    begin
     Read(a,j);
     z[-1,i]:=j;
    end;
   for j:=1 to y do
    begin
     Read(a,i);
     z[j,-1]:=i;
    end;
   for i:=1 to y do
    for j:=1 to x do
     begin
      if z[-1,j]=z[i,-1] then z[i,j]:=z[i-1,j-1]+1 else z[i,j]:=max(z[i-1,j],z[i,j-1]);
      if z[i,j]>k then k:=z[i,j];
     end;
     for i:=1 to y do
     begin
      for j:=1 to x do
        Write(z[i,j]:4);
      Writeln;
      end;

     Writeln(b,k);
    if k>0 then
    begin
     xk:=y+1; yk:=x+1;
   for j:=x downto 1 do
    for i:=y downto 1 do
    if k>=1 then
     if (z[i,j]=k) and (z[-1,j]=z[i,-1]) and (i<xk) and (j<yk) then begin xx[k]:=z[-1,j]; xk:=i; yk:=j; k:=k-1; end;
     end;
     i:=k;
     i:=1;
    while xx[i]<>0 do
     begin
      Write(b,xx[i],' ');
      i:=i+1;
     end;
   close(b);
  end.
