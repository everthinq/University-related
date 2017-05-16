%a = 20.2
%b = 7.65

value(3.56).
value(4.02).
value(3.84).
value(1.98).
value(2.34).
value(6.57).

func :-
	value(X), 
	Y = ( (sqrt(20.2 * X) - 7.65) / ((tan * X) * (tan * X) * (tan * X)) ),
	write(Y), nl, fail.


%3.5
%4
%0.1