program algoritmul_lui_euclid;
 
var a,b,i,t:longint;
    f,g:text;
  
  
  function cmmdc(a,b:longint):longint;               //recursiv
  
  begin
    if a mod b=0 then cmmdc:=b                      //calculam cu ajutorul
                 else cmmdc:=cmmdc(b,a mod b);      //resturilor impartirii
  end;
  
  
  
BEGIN
  
  assign(f,'euclid2.in');reset(f);
  assign(g,'euclid2.out');rewrite(g);
  readln(f,t);
  for i:=1 to t do
    begin
      readln(f,a,b);
      if a<b then writeln(g,cmmdc(a,b))            //in functie de minim executam recursia
             else writeln(g,cmmdc(b,a));
    end;
  
  close(f);
  close(g);
  
END.