program cmlsc;
 var a,b:text;
  i,j,k,x,y,xk,yk:integer;
  z:array[-1..1024,-1..1024] of byte;
  function max(i,j:byte):byte;
   begin
   if i>j then max:=i else max:=j;
   end;
  begin
   assign(a,'cmlsc/grader_test1.in');
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
      if z[i,j]>k then begin k:=z[i,j]; xk:=i; yk:=j; end;
     end;
     Writeln(b,k);
    if k>0 then
    begin
    k:=1;
   for j:=1 to x do
    for i:=1 to y do
     if (z[i,j]=k) and (z[-1,j]=z[i,-1]) then begin Write(b,z[-1,j],' '); inc(k); end;
     end;
   close(b);
  end.
