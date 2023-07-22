#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &t1, T &t2)
{
	T aux;
	aux = t1;
	t1 = t2;
	t2 = aux;
}

template <typename N>
const N &min(N &t1, N &t2)
{
	if (t1 == t2)
		return (t2);
	else if (t1 < t2)
		return (t1);
	else
		return (t2);
}

template <typename N>
const  N &max(N &t1, N &t2)
{
	if (t1 == t2)
		return (t2);
	else if (t1 > t2)
		return (t1);
	else
		return (t2);
}

#endif
