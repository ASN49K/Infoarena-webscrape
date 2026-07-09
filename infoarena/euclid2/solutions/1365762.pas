program euclid2;
var a,b,i,t,aux:longint;
    f,g:text;

  function cmmdc(a,b:longint):longint;     //recursiv
  begin
    if b=0 then cmmdc:=a                   //calculam cu ajutorul
        else cmmdc:=cmmdc(b,a mod b);      //resturilor impartirii
  end;

BEGIN

  assign(f,'euclid2.in');reset(f);
  assign(g,'euclid2.out');rewrite(g);
  readln(f,t);
  for i:=1 to t do
    begin
      readln(f,a,b);
      if a<b then           //in locul lui b
        begin               //il punem pe minimul din
          aux:=a;           //aceste 2 numere
          a:=b;
          b:=aux;
        end;
      writeln(g,cmmdc(a,b));
    end;

  close(f);
  close(g);

END.
