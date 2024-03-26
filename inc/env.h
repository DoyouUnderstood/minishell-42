/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:39:15 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 15:09:30 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "hash_map.h"

t_hash_map	*env(void);
int			env_init(char **envp);
void		env_destroy(void);
int			env_set(char *key, char *value);
void		env_unset(char *key);
char		*env_get(char *key);
char		**env_to_arr(void);

#endif