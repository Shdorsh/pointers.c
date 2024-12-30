/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abredimu <abredimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 07:42:41 by abredimu          #+#    #+#             */
/*   Updated: 2024/12/30 11:02:46 by abredimu         ###   ########.fr       */
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
}	t_pointer;

t_pointer	num_create_pointer(long l);
t_pointer	ref_create_pointer(void *vp);
int			compare_pointer_values(t_pointer a, t_pointer b);
t_pointer	stack_search(t_pointer ptr, t_pointer value, int similitude);
t_pointer	stack_down(t_pointer ptr, int amount);

#endif
