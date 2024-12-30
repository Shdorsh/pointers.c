/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abredimu <abredimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 07:45:58 by abredimu          #+#    #+#             */
/*   Updated: 2024/12/30 06:49:41 by abredimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pointer.h"

// Creates a pointer union variable from a long/int. Best used for nulling easily
pointer	num_create_pointer(long l)
{
	pointer	result;

	result.l = l;
	return (result);
}

// Creates a pointer union variable from another reference.
pointer	ref_create_pointer(void *vp)
{
	pointer	result;

	result.vp = vp;
	return (result);
}

// Compares two pointers' values and returns a value according to how many bytes
// are identical.
int	compare_pointer_values(pointer a, pointer b)
{
	int	result;

	result = 0;
	result += *a.cp == *b.cp;
	result += *a.sp == *b.sp;
	result += *a.ip == *b.ip;
	result += *a.lp == *b.lp;
	return (result);
}

// Searches for the next pointer downwards in the stack until it finds the same
// value as the value pointer given.
// The similitude is defined by how many types both pointer values are equal to.
// It compares the values pointed to and gives a different int depending on matching
// type:
// Returns:
//  - 0 if values differ for all types
//  - 1 if char values match
//  - 2 if short values match
//  - 3 if int values match
//  - 4 if long values match
pointer	stack_search(pointer ptr, pointer value, int similitude)
{

	while (compare_pointer_values(ptr, value) >= similitude)
	{
		ptr = stack_down(ptr, 1);
		if (!ptr.vp)
			return (ptr);
	}
	return (ptr);
}

// Goes down the stack by one spot. If it were to go below null value, returns
// a null union pointer
pointer	stack_down(pointer ptr, int amount)
{
	long	mod;

	mod = sizeof (*ptr.ip);
	if (!mod)
		mod = sizeof (int);
	mod *= amount;
    if (mod > ptr.l)
        return (num_create_pointer(0));
    ptr.l = (ptr.l - mod) / sizeof (int) * sizeof (int);
    return (ptr);
}
