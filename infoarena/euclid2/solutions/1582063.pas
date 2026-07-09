program euclid;
 var
     a,b,n,i:longint;
     fin,fou:text;
 function cmmdc(a,b:longint):longint;
  begin
    if b=0 then cmmdc:=a
    else cmmdc:=cmmdc(b,a mod b);
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
