program test;
const
  M = 1;
  L = 0.0;
type
  int = integer;

  i = integer;

  v = record
    q : int;
    w : Integer;
    e : array[0..10] of char;
  end;

  p = array[0..10] of v;

  q = array[0..11] of Real;
var
  i : integer;
  a : array[0..10] of Integer;
  x : v;

procedure Proc(x : int);
begin
  x := 0;
end;

function Fun(x : real) : Real;
var
  y : real;
begin
  y := 2 * x;
end;

begin

  case i of
    1 : i := i + 1;
    2 : i := i + 1;
    3 : i := i + 1;
    4 : i := i + 1;
  end;

  i := 0;
  for i := 0 to 100 do
  begin
    i := i + 1;
  end;

  while i < 0 do
  begin
    i := i + 1;
  end;

  if i <> 2 then
  begin
    i := i - 1;
  end
  else
  begin
    i := i + 1;
  end;

  Proc(9);

  i := Fun(3.3);

  a[2] := 3;

  x.q := 3;

end.
