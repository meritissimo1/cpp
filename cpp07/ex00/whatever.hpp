#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename GENERIC>
void swap(GENERIC &t1, GENERIC &t2)
{
	GENERIC aux;
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
