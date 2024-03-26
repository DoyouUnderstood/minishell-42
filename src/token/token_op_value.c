/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_op_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:25 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 18:36:41 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"
/** Returns the string value of an operator token,
 * or NULL if invalid.
 * 
 * The returned value needs to be freed.
*/
char	*op_value(t_token_type type)
{
	if (type == T_AND)
		return (ft_strdup("&&"));
	else if (type == T_OR)
		return (ft_strdup("||"));
	else if (type == T_PIPE)
		return (ft_strdup("|"));
	else if (type == T_REDIR_IN)
		return (ft_strdup("<"));
	else if (type == T_REDIR_OUT)
		return (ft_strdup(">"));
	else if (type == T_REDIR_HEREDOC)
		return (ft_strdup("<<"));
	else if (type == T_REDIR_APPEND)
		return (ft_strdup(">>"));
	else if (type == T_PAREN_OPEN)
		return (ft_strdup("("));
	else if (type == T_PAREN_CLOSE)
		return (ft_strdup(")"));
	else if (type == T_EOF)
		return (ft_strdup("newline"));
	return (NULL);
}
