Program CMMDC_Tudor;
var fi,fo : text;
    a,b,nr : integer;

Function CMMDC(a,b : integer) : integer;
begin
      if a mod b = 0 then CMMDC:=b
                     else CMMDC:=CMMDC(b,a mod b);
end;

begin
      assign(fi,'CMMDC.IN');
      reset(fi);
      read(fi,a,b);
      close(fi);

      assign(fo,'CMMDC.out');
      rewrite(fo);

      if a>b then nr:=CMMDC(a,b)
             else nr:=CMMDC(b,a);
      if nr<>1 then write(fo,nr)
               else write(fo,'0');
      close(fo);
end.