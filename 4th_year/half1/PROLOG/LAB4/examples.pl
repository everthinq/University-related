country(england).
country(france).
country(germany).
country(denmark).
print_countries:-country(X),
	write(X),
	nl,
	fail.


typewriter :- 
	repeat,
	read(C),
	write(C).


fact(X, F) :- 
	(X = 0, F = 1; 
	Y is X-1, 
	fact(Y, Z),
	F is X*Z),
	write(X),
	write('! = '),
	write(F), nl.