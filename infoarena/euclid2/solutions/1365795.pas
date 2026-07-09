program algoritmul_lui_euclid;

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
      if a<b then                 //in functie de minim executam recursia
        writeln(g,cmmdc(a,b))
          else writeln(g,cmmdc(b,a));
    end;

  close(f);
  close(g);

END.
