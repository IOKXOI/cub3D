/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:44:40 by sydauria          #+#    #+#             */
/*   Updated: 2021/12/20 01:03:26 by sydauria         ##   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int    ft_atoi(const char *str)
{
    size_t    nb;
    int        sign;

    nb = 0;
    sign = 1;
    while (*str == ' ')
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    if (*str < '0' || *str > '9')
        return (-1);
    while (*str >= '0' && *str <= '9')
        nb = nb * 10 + (*(str)++ - 48);
    while (*str++)
    {
        if (*str != ' ' && *str != '\n')
            return (-1);
    }
    return (sign * nb);
}
