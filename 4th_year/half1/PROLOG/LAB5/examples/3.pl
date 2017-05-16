palindrome([]).
palindrome([_]).
palindrome(List) :-
    append([H|T], [H], List),
    palindrome(T).