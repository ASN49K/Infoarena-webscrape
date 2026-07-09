Program CMMDC_Tudor;
var fi,fo : text;
    a,b,nr,i,n : integer;

Function CMMDC(a,b : integer) : integer;
begin
      if a mod b = 0 then CMMDC:=b
                     else CMMDC:=CMMDC(b,a mod b);
end;

begin
      assign(fi,'euclid2.in');
      reset(fi);
      readln(fi,n);
      assign(fo,'euclid2.out');
      rewrite(fo);

      for i:=1 to n do begin
      read(fi,a,b);
      if a>b then nr:=CMMDC(a,b)
             else nr:=CMMDC(b,a);
      writeln(fo,nr);
                       end;


      close(fi);
      close(fo);
end.