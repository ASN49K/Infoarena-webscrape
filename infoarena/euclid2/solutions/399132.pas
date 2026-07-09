const infile='euclid2.in';
  outfile='euclid2.out';
var f,g:text;
  a,b,t:longint;

 function cmmdc(a,b:longint):longint;
 var r:longint;
 begin
   repeat
     r:=a mod b;
     a:=b; b:=r;
   until b=0;
   cmmdc:=a;
 end;

begin
 assign(f,infile); reset(f); readln(f,t);
 assign(g,outfile); rewrite(g);
 while(t>0)do begin
   readln(f,a,b); writeln(g,cmmdc(a,b)); dec(t);
 end;
 close(f); close(g);
end.
