program cel_mai_lung_subsir_comun;
type vector=array[1..1000] of integer;

var A,B,q,v,sol:vector;
    i,nA,nB,m,solD:integer;


procedure actualizare(tab:vector; m:integer);
var i,j,k,dif,dif1:integer;
    EBun:boolean;
    AC:set of 1..255;
begin
   for i:=1 to m do include(ac,b[q[i]]);
   for j:=1 to na do if not(tab[j] in ac) then tab[j]:=0;

   for k:=na downto 1 do if tab[k]<>0 then break;
   dif:=tab[k];
   for i:=k-1 downto 1 do dif:=dif-tab[i];
   dif1:=b[q[m]];
   for i:=m-1 downto 1 do dif1:=dif1-b[q[i]];
   if dif<>dif1 then ebun:=false
   else ebun:=true;
  // if ebun then for i:=1 to m do write(b[q[i]],' ');
  // if ebun then writeln;
     if (ebun) and (solD<m) then
     begin
         for i:=1 to m do sol[i]:=b[q[i]];
         solD:=m;
     end;
end;

procedure back(curent:integer);
var i:integer;
begin
     // for i:=1 to m do write(q[i],' ');
     // writeln;
     if m>0 then
     actualizare(a,m);
      if curent<=nb then
      for i:=curent to nb do
      begin
          inc(m);
          q[m]:=v[i];
          back(i+1);
          dec(m);
      end;

end;

begin
    assign(input,'cmlsc.in'); reset(input);
    assign(output,'cmlsc.out'); rewrite(output);
    readln(input,nA,nB);
    if nA>Nb then
    begin
    for i:=1 to nA do read(a[i]);
    for i:=1 to nB do read(b[i]);
    end else
           begin
               for i:=1 to na do read(b[i]);
               for i:=1 to nb do read(a[i]);
               na:=na xor nb;
               nb:=na xor nb;
               na:=na xor nb;
           end;
    m:=0;
    for i:=1 to nb do v[i]:=i;
    sold:=0;
    back(1);
    writeln(output,solD);
    for i:=1 to solD do write(output,sol[i],' ');
   { for i:=1 to na do write(a[i],' ');
    writeln;
    for i:=1 to nb do write(b[i],' '); }
    close(input); close(output);
end.
