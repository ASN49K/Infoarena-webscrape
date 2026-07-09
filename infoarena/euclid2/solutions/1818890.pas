Program P1;
  var fi,fo:text;
      a,b,d:integer;
begin
    assign(fi,'cmmdc.in');
    assign(fo,'cmmdc.out');
    reset(fi);
    rewrite(fo);
    read(fi,a,b);
    while a<>b do
          If a>b then a:=a-b else b:=b-a;
    If a=1 then d:=0 else d:=a;
    write(fo,d);
    close(fi);
    close(fo);
end.
















