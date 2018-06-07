program p;
type
  T = record
    x:Integer;
    t:T;
  end;
var
  x : T;
  y : T;

begin
  x.x := 1;
  y.t := x;
end.
