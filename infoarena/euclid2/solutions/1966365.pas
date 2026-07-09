program euclid;

type numar=record
      nr1,nr2,di:word;
      end;

  var c:array[1..100010] of numar;
      n,a,b,i:word;
      fi,fo:text;


  function cmmdc(a,b:word):word;
  begin
  if a=0 then cmmdc:=b
    else cmmdc:=cmmdc(b mod a,a);

 end;
begin  assign(fi,'euclid2.in'); assign(fo,'euclid2.out');
  readln(fi,n);
  for i:=1 to n do
     begin
     read(fi,c[i].nr1); readln(fi,c[i].nr2);
     c[i].di:=cmmdc(c[i].nr1,c[i].nr2);
     end;
   close(fi);
  for i:=1 to n do
    writeln(fo,c[i].di);
  close(fo);

  end.


