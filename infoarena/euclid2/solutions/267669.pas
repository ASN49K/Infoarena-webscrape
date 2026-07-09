program divizorul_comun;
var aux,cmmdc,nr,i,a,b:integer;
    f:text;
    vector:array[1..100] of integer;
begin
  assign(f,'cmmdc.in');
  reset(f);
  readln(f,nr);
  for i:=1 to nr*2 do
    begin
      read(f,vector[i]);
    end;
  close(f);
  assign(f,'cmmdc.out');
  rewrite(f);
  i:=1;

  while(vector[i]<>0) do
    begin

      a:=vector[i];
      b:=vector[i+1];
      i:=i+2;
      if(b=0) then cmmdc:=a;
      while(b<>0) do
        begin
          aux:=a mod b;
          a:=b;
          b:=aux;
          cmmdc:=a;
        end;
      writeln(f,cmmdc);
    end;
  close(f);
end.
