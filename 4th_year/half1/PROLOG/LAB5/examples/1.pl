is_lst([]) :- !.
is_lst([H|T]) :-
	is_lst(T).

len([], 0).
len([H|T], N) :- 
	len(T, M),  
	N is M + 1,
	check_even_or_odd(N).

even(X) :-
	Y is mod(X, 2),
	Y =:= 0.

odd(X) :-
	Y is mod(X, 2),
	Y \= 0.

write_list([Head|Tail]) :-
	write(Head), nl,
	write_list(Tail).

check_even_or_odd(X) :- 
	Y is mod(X, 2),
	Y =:= 0 -> write('its even'); true,
	write('its odd'), false.

main :-
	length([1,2,3,4,5,6,7,8], X),
	check_even_or_odd(X).