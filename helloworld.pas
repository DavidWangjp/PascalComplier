program p;
var
  y : Integer;

function func_out(x : Integer) : Integer;
  function func_in(y : Integer) : Integer;
  begin
    func_in := x + y;
  end;

begin
  func_out := func_in(1);
end;


begin
  y := func_out(2);
end.