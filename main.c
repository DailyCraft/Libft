/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:46 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/04 15:52:36 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

/**
 * Not tested here:
 * - ft_strlcpy()
 * - ft_strlcat()
*/
int	main(void) {
	for (int i = 0; i < 128; i++)
	{
		if (!((isalpha(i) != 0 && ft_isalpha(i) != 0) || (isalpha(i) == 0 && ft_isalpha(i) == 0)))
			printf("isalpha('%c'): Error\n", i);
		if (!((isdigit(i) != 0 && ft_isdigit(i) != 0) || (isdigit(i) == 0 && ft_isdigit(i) == 0)))
			printf("isdigit('%c'): Error\n", i);
		if (!((isalnum(i) != 0 && ft_isalnum(i) != 0) || (isalnum(i) == 0 && ft_isalnum(i) == 0)))
			printf("isalnum('%c'): Error\n", i);
		if (!((isascii(i) != 0 && ft_isascii(i) != 0) || (isascii(i) == 0 && ft_isascii(i) == 0)))
			printf("isascii('%c'): Error\n", i);
		if (!((isprint(i) != 0 && ft_isprint(i) != 0) || (isprint(i) == 0 && ft_isprint(i) == 0)))
			printf("isprint('%c'): Error\n", i);
		
		if (toupper(i) != ft_toupper(i))
			printf("toupper('%c'): Error\n", i);
		if (tolower(i) != ft_tolower(i))
			printf("tolower('%c'): Error\n", i);
	}

	for (int i = 0; i < 50; i++)
	{
		char str[i + 1];
		for (int j = 0; j < i; j++)
			str[j] = 'a';
		str[i] = 0;

		if (strlen(str) != ft_strlen(str))
			printf("strlen('%s'): Error\n", str);
		if (strcmp(strdup(str), ft_strdup(str)) != 0)
			printf("strdup(\"%s\"): Error\n", str);

		// Also check ft_bzero()
		for (int j = 0; j < i + 1; j++) { // memset with ' '
			char *off = ft_strdup(str), *ft = ft_strdup(str);
			memset(ft_strdup(str), ' ', j);
			ft_memset(ft_strdup(str), ' ', j);
			if (strcmp(off, ft) != 0)
				printf("memset(\"%s\", %d): Error\n", str, j);
		}
		for (int j = 0; j < i + 1; j++) { // memset with -1000
			char *off = ft_strdup(str), *ft = ft_strdup(str);
			memset(ft_strdup(str), -1000, j);
			ft_memset(ft_strdup(str), -1000, j);
			if (strcmp(off, ft) != 0)
				printf("memset(\"%s\", %d): Error\n", str, j);
		}
	}

	if (atoi("   a") != ft_atoi("   a")) printf("atoi(\"%s\"): Error\n", "   a");
	if (atoi("   1a") != ft_atoi("   1a")) printf("atoi(\"%s\"): Error\n", "   1a");
	if (atoi("-451215a") != ft_atoi("-451215a")) printf("atoi(\"%s\"): Error\n", "-451215a");
	if (atoi("--451215a") != ft_atoi("--451215a")) printf("atoi(\"%s\"): Error\n", "--451215a");
	if (atoi("") != ft_atoi("")) printf("atoi(\"%s\"): Error\n", "");
	if (atoi("42") != ft_atoi("42")) printf("atoi(\"%s\"): Error\n", "42");
	if (atoi("2147483647") != ft_atoi("2147483647")) printf("atoi(\"%s\"): Error\n", "2147483647");
	if (atoi("-2147483648") != ft_atoi("-2147483648")) printf("atoi(\"%s\"): Error\n", "-2147483648");

	char *str;
	str = "baaa";
	if (strchr(str, 'b') != ft_strchr(str, 'b')) printf("strchr(\"%s\"): Error\n", str);
	if (strrchr(str, 'b') != ft_strrchr(str, 'b')) printf("strrchr(\"%s\"): Error\n", str);
	if (strstr(str, "b") != ft_strnstr(str, "b", 10)) printf("strnstr(\"%s\"): Error\n", str);
	str = "aaab";
	if (strchr(str, 'b') != ft_strchr(str, 'b')) printf("strchr(\"%s\"): Error\n", str);
	if (strrchr(str, 'b') != ft_strrchr(str, 'b')) printf("strrchr(\"%s\"): Error\n", str);
	if (strstr(str, "b") != ft_strnstr(str, "b", 10)) printf("strnstr(\"%s\"): Error\n", str);
	str = "aaa";
	if (strchr(str, 'b') != ft_strchr(str, 'b')) printf("strchr(\"%s\"): Error\n", str);
	if (strrchr(str, 'b') != ft_strrchr(str, 'b')) printf("strrchr(\"%s\"): Error\n", str);
	if (strstr(str, "b") != ft_strnstr(str, "b", 10)) printf("strnstr(\"%s\"): Error\n", str);
	
	str = "";
	if (strchr(str, 'b') != ft_strchr(str, 'b')) printf("strchr(\"%s\"): Error\n", str);
	if (strrchr(str, 'b') != ft_strrchr(str, 'b')) printf("strrchr(\"%s\"): Error\n", str);
	if (strstr(str, "b") != ft_strnstr(str, "b", 10)) printf("strnstr(\"%s\"): Error\n", str);
	
	str = "aabaa";
	if (strchr(str, 'b') != ft_strchr(str, 'b')) printf("strchr(\"%s\"): Error\n", str);
	if (strrchr(str, 'b') != ft_strrchr(str, 'b')) printf("strrchr(\"%s\"): Error\n", str);
	if (strstr(str, "b") != ft_strnstr(str, "bg", 1)) printf("strnstr(\"%s\", \"%s\", %d): Error\n", str, "bg", 1);
	if (strstr(str, "bg") != ft_strnstr(str, "bg", 2)) printf("strnstr(\"%s\", \"%s\", %d): Error\n", str, "bg", 2);

	if (strncmp("aab", "baa", 3) != ft_strncmp("aab", "baa", 3))
		printf("strncmp(\"%s\", \"%s\", %d): Error\n", "aab", "baa", 3);
	if (strncmp("baa", "baa", 4) != ft_strncmp("baa", "baa", 4))
		printf("strncmp(\"%s\", \"%s\", %d): Error\n", "baa", "baa", 4);
	if (strncmp("aaab", "aaaa", 4) != ft_strncmp("aaab", "aaaa", 4))
		printf("strncmp(\"%s\", \"%s\", %d): Error\n", "aaab", "aaaa", 4);
	if (strncmp("aaab", "aaaa", 5) != ft_strncmp("aaab", "aaaa", 5))
		printf("strncmp(\"%s\", \"%s\", %d): Error\n", "aaab", "aaaa", 5);
	if (strncmp("aaab", "aaaa", 3) != ft_strncmp("aaab", "aaaa", 3))
		printf("strncmp(\"%s\", \"%s\", %d): Error\n", "aaab", "aaaa", 3);
}