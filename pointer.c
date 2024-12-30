/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abredimu <abredimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 07:45:58 by abredimu          #+#    #+#             */
/*   Updated: 2024/12/30 11:02:07 by abredimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pointer.h"

// Creates a pointer union variable from a long/int.
// Best used for nulling easily
t_pointer	num_create_pointer(long l)
{
	t_pointer	result;

	result.l = l;
	return (result);
}

// Creates a pointer union variable from another reference.
t_pointer	ref_create_pointer(void *vp)
{
	t_pointer	result;

	result.vp = vp;
	return (result);
}

// Compares two pointers' values and returns a value according to how many bytes
// are identical.
int	compare_pointer_values(t_pointer a, t_pointer b)
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
// It compares the values pointed to and gives a different int depending on
// matching type:
// Returns:
//  - 0 if values differ for all types
//  - 1 if char values match
//  - 2 if short values match
//  - 3 if int values match
//  - 4 if long values match
t_pointer	stack_search(t_pointer ptr, t_pointer value, int similitude)
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
t_pointer	stack_down(t_pointer ptr, int amount)
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
