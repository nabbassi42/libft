/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabbassi <nabbassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:46:11 by nabbassi          #+#    #+#             */
/*   Updated: 2020/03/02 18:28:01 by nabbassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int		mots;
	int		i;

	mots = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			mots++;
		if (s[i] != c && (i > 0 && s[i - 1] == c))
			mots++;
		i++;
	}
	return (mots);
}

static void	remplir_tableau(char **answer, char const *s, char c)
{
	int		i;
	int		index_mot;
	int		debut_mot;
	int		taille_mot;

	i = 0;
	index_mot = -1;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			debut_mot = i;
			index_mot++;
		}
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			taille_mot = i - debut_mot + 1;
			answer[index_mot] = malloc(taille_mot + 1);
			ft_memcpy(answer[index_mot], s + debut_mot, taille_mot);
			answer[index_mot][taille_mot] = '\0';
		}
		i++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	int		nombre_de_mots;
	char	**answer;

	nombre_de_mots = words(s, c);
	answer = malloc((nombre_de_mots + 1) * sizeof(char *));
	answer[nombre_de_mots] = NULL;
	remplir_tableau(answer, s, c);
	return (answer);
}

/*
** int (void)main()
**
** {
** char s1[] = "bonjour caff vad";
** printf("%s\n", *ft_strsplit(s1, 'a'));
** return(0);
** }
*/