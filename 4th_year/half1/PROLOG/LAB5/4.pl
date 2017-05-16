is_even(X) :-
	Y is mod(X, 2),
	Y =:= 0.

main :-
	append([1,2,3], [4,5,6,7,8,9], X),
	length(X, Len), Half_len is (ceiling(Len / 2) - 1),
	is_even(Len) -> nth0(Half_len, X, Elem), write(Elem); true,
	append([1,2,3], [4,5,6,7,8,9], X),
	length(X, Len),
	Half_len1 is (ceiling(Len / 2) - 2),
	Half_len2 is (ceiling(Len / 2) - 1),
	nth0(Half_len1, X, Elem1), write(Elem1), nl,
	nth0(Half_len2, X, Elem2), write(Elem2), true.