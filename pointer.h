/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abredimu <abredimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 07:42:41 by abredimu          #+#    #+#             */
/*   Updated: 2024/12/27 09:05:12 by abredimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTER_H
# define POINTER_H
# include <stdint.h>
# include <stdio.h>

typedef union pointer
{
	void		*vp;
	char		*cp;
	short		*sp;
	int			*ip;
	long		*lp;
	uintptr_t	uip;
	long		l;
}	pointer;

pointer	num_create_pointer(long l);
pointer	ref_create_pointer(void *vp);
int		compare_pointer_values(pointer a, pointer b);
pointer	stack_search(pointer ptr, pointer value, int similitude);
pointer	stack_down(pointer ptr, int amount);

#endif
