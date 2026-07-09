   program gr2;
      var a,b,c,delta:real;
      x1,x2:real;
      begin
      readln(a,b,c);
      delta:=sqr(b)-4*a*c;
      if delta<0 then writeln('ecuatia nu are solutii reale') else
      if delta=0then  writeln('ecuatia are o solutie: ',-b/(2*a)) else
      writeln ('ecuatia are 2 sol.:',-b-sqrt(delta)/(2*a):2:2,' si ',-b+sqrt(delta)/(2*a):2);

     readln
     end.