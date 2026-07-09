Program algoreuclid;

VAR


a,b,c,t,i:longint;
cin,cout:text;

begin
  assign(cin,'euclid2.in');
  reset(cin);
  assign(cout,'euclid2.out');
  rewrite(cout);

  read(cin,t);
  for i:=1 to t do
  begin
    read(cin,a,b);
    while (a>0) and (b>0) do
    begin
     if (a>b)
      then
       a:=a-b
      else
       b:=b-a;
    end;
    if (a>b)
    then
      c:=a
    else
      c:=b;
    writeln(cout,c);
  end;


  close(cin);
  close(cout);
end.
