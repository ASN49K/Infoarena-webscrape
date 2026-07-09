program euclid;
 var n,i:integer;
     a,b:longint;
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
 readln(fin,n);
 for i:=1 to n do
   begin
    readln(fin,a,b);
    writeln(fou,cmmdc(a,b));
   end;
 close(fin);
 close(fou);
end.
