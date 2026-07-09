program euclid;
 var a,b:longint;
     fin,fou:text;
 function cmmdc(a,b:longint):longint;
  var r:longint;
  begin
   r:=1;
    while r>0 do
     begin
      r:=a mod b;
      a:=b;
      b:=r;
     end;
    cmmdc:=a;
  end;



begin
 assign(fin,'euclid2.in');
 assign(fou,'euclid2.out');
 reset(fin);
 rewrite(fou);
 read(fin,a,b);
 write(fou,cmmdc(a,b));
 close(fin);
 close(fou);
end.
