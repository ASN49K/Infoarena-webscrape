Program CelMaiMareDivizorComun;   
var Intrare,Iesire : text;   
  
procedure DeschideFisiere;   
begin  
  assign(Intrare,'euclid2.in');   
  assign(Iesire,'euclid2.out');   
  reset(Intrare);   
  rewrite(Iesire);   
end;   
  
function cmmdc(a,b : longint) : longint;   
begin  
  while (a<>0) and (b<>0) do  
   if a>b then a:=a mod b else b:=b mod a;   
  if a>0 then cmmdc:=a else cmmdc:=b;   
end;   
  
procedure Proceseaza;   
var T,i,a,b : longint;   
begin  
  readln(Intrare,T);   
  for i:=1 to T do begin  
    readln(Intrare,a,b);   
    writeln(Iesire,cmmdc(a,b));   
  end;   
end;   
  
procedure InchideFisiere;   
begin  
  close(Intrare);   
  close(Iesire);   
end;   
  
begin  
  DeschideFisiere;   
  Proceseaza;   
  InchideFisiere;   
end.  
