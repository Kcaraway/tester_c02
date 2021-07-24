#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define RED     "\33[1;31m"
#define GREEN   "\33[1;32m"
#define RESET   "\33[1;0m"

// #define STR_ISALPHA 1

#ifdef STRCPY
char*	ft_strcpy(char *s1, char *s2);
#else
# define STRCPY 0
#endif

#ifdef STRNCPY
char*	ft_strncpy(char *s1, char *s2, unsigned int n);
#else
# define STRNCPY 0
#endif

#ifdef STR_ISALPHA
int	ft_str_is_alpha(char *s1);
#else
# define STR_ISALPHA 0
#endif

#ifdef STR_ISNUMERIC
int	ft_str_is_numeric(char *s1);
#else
# define STR_ISNUMERIC 0
#endif

#ifdef STR_ISLOWERCASE
int	ft_str_is_lowercase(char *s1);
#else
# define STR_ISLOWERCASE 0
#endif

#ifdef STR_ISUPPERCASE
int	ft_str_is_uppercase(char *s1);
#else
# define STR_ISUPPERCASE 0
#endif


int		str_is_alpha(char *str) {
	while (*str != '\0') {
		if (!isalpha(*str++))
			return (0);
	}
	return (1);
}

int		str_is_numeric(char *str) {
	while (*str != '\0') {
		if (!isnumber(*str++))
			return (0);
	}
	return (1);
}

int		str_is_lowercase(char *str) {
	while (*str != '\0') {
		if (!islower(*str++))
			return (0);
	}
	return (1);
}

int		str_is_uppercase(char *str) {
	while (*str != '\0') {
		if (!isupper(*str++))
			return (0);
	}
	return (1);
}

void check_int_fatal(void *buffer)
{
	if (!buffer)
	{
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		exit(1);
	}
}

void ok()
{
	write(1, GREEN, strlen(GREEN));
	write(1, "[OK]", 5);
	write(1, RESET, strlen(RESET));
}

void ko()
{
	write(1, RED, strlen(RED));
	write(1, "[KO]", 5);
	write(1, RESET, strlen(RESET));
}

int		main()
{
#if STRCPY
	char* dest = malloc(100);
	char* src = malloc(50);
	char* buffer = malloc(100);
	char* buffer2 = malloc(100);

	bzero(src, 100);
	memset(src, 'a', 99);
	
	sprintf(buffer, "%s", ft_strcpy(dest, src));
	free(dest);
	dest = malloc(100);
	sprintf(buffer2, "%s", strcpy(dest, src));
	write(1, "STRCPY:", strlen("STRCPY:"));
	if (!strcmp(buffer, buffer2)) {
		ok();
	} else {
		ko();
	}
	write(1, "\n", 1);
	free(dest);
	free(src);
	// free(buffer);
	// free(buffer2);
#endif

#if STRNCPY
	char* dest1 = malloc(100);//UINT32_MAX
	char* src1 = calloc(50, 1);
	char* buffer1 = malloc(100);
	char* buffer12 = malloc(100);

	bzero(src1, 100);
	memset(src1, 'a', 99);
	
	sprintf(buffer1, "%s", ft_strncpy(dest1, src1, 10));
	free(dest1);
	dest1 = malloc(100);
	sprintf(buffer12, "%s", strncpy(dest1, src1, 10));
	write(1, "STRNCPY:", strlen("STRNCPY:"));
	if (!strcmp(buffer1, buffer12)) {
		ok();
	} else {
		ko();
	}
	free(dest1);
	free(src1);
	// free(buffer1);
	// free(buffer12);

	dest1 = malloc(UINT32_MAX);
	src1 = calloc(UINT32_MAX, 1);
	buffer1 = malloc(UINT32_MAX);
	buffer12 = malloc(UINT32_MAX);

	memset(src1, 'z', UINT32_MAX - 1);
	
	sprintf(buffer1, "%s", ft_strncpy(dest1, src1, UINT32_MAX));
	free(dest1);
	dest1 = malloc(UINT32_MAX);
	sprintf(buffer12, "%s", strncpy(dest1, src1, UINT32_MAX));
	if (!strcmp(buffer1, buffer12)) {
		ok();
	} else {
		ko();
	}
	write(1, "\n", 1);
	free(dest1);
	free(src1);
	// free(buffer1);
	// free(buffer12);

#endif

#if STR_ISALPHA
	char q1[] = "Nadaaver";
	char q2[] = "Teste de Com1paracao";
	char q3[] = "Teste-";
	char q4[] = "Teste@";
	char q5[] = "Teste[";
	char q6[] = "Teste\'";
	char q7[] = "Teste{";
	char* zbuffer = malloc(100);
	char* zbuffer2 = malloc(100);

	write(1, "STR_IS_ALPHA:", strlen("STR_IS_ALPHA:"));
	sprintf(zbuffer, "%d", ft_str_is_alpha(q1));
	sprintf(zbuffer2, "%d", str_is_alpha(q1));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	sprintf(zbuffer, "%d", ft_str_is_alpha(q2));
	sprintf(zbuffer2, "%d", str_is_alpha(q2));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	sprintf(zbuffer, "%d", ft_str_is_alpha(q3));
	sprintf(zbuffer2, "%d", str_is_alpha(q3));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	sprintf(zbuffer, "%d", ft_str_is_alpha(q4));
	sprintf(zbuffer2, "%d", str_is_alpha(q4));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	sprintf(zbuffer, "%d", ft_str_is_alpha(q5));
	sprintf(zbuffer2, "%d", str_is_alpha(q5));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	sprintf(zbuffer, "%d", ft_str_is_alpha(q6));
	sprintf(zbuffer2, "%d", str_is_alpha(q6));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	sprintf(zbuffer, "%d", ft_str_is_alpha(q7));
	sprintf(zbuffer2, "%d", str_is_alpha(q7));
	if (!strcmp(zbuffer, zbuffer2))
		ok();
	else
		ko();
	// free(zbuffer);
	// free(zbuffer2);
	write(1, "\n", 1);
#endif

#if STR_ISNUMERIC
	char k1[] = "123";
	char k2[] = "789/";
	char k3[] = "0123:";
	char k4[] = "Teste@";
	char* ybuffer = malloc(100);
	char* ybuffer2 = malloc(100);

	write(1, "STR_IS_NUMERIC:", strlen("STR_IS_NUMERIC:"));
	sprintf(ybuffer, "%d", ft_str_is_numeric(k1));
	sprintf(ybuffer2, "%d", str_is_numeric(k1));
	if (!strcmp(ybuffer, ybuffer2))
		ok();
	else
		ko();
	sprintf(ybuffer, "%d", ft_str_is_numeric(k2));
	sprintf(ybuffer2, "%d", str_is_numeric(k2));
	if (!strcmp(ybuffer, ybuffer2))
		ok();
	else
		ko();
	sprintf(ybuffer, "%d", ft_str_is_numeric(k3));
	sprintf(ybuffer2, "%d", str_is_numeric(k3));
	if (!strcmp(ybuffer, ybuffer2))
		ok();
	else
		ko();
	sprintf(ybuffer, "%d", ft_str_is_numeric(k4));
	sprintf(ybuffer2, "%d", str_is_numeric(k4));
	if (!strcmp(ybuffer, ybuffer2))
		ok();
	else
		ko();
	// free(ybuffer);
	// free(ybuffer2);
	write(1, "\n", 1);
#endif

#if STR_ISLOWERCASE
	char t1[] = "nadaaver";
	char t2[] = "Teste";
	char t3[] = "teste";
	char t4[] = "Teste@";
	char t5[] = "Teste[";
	char t6[] = "Teste\'";
	char t7[] = "Teste{";
	char* rbuffer = malloc(100);
	char* rbuffer2 = malloc(100);

	write(1, "STR_IS_LOWERCASE:", strlen("STR_IS_LOWERCASE:"));
	sprintf(rbuffer, "%d", ft_str_is_alpha(t1));
	sprintf(rbuffer2, "%d", str_is_alpha(t1));
	if (!strcmp(rbuffer, rbuffer2))
		ok();
	else
		ko();
	sprintf(rbuffer, "%d", ft_str_is_alpha(t2));
	sprintf(rbuffer2, "%d", str_is_alpha(t2));
	if (!strcmp(rbuffer, rbuffer2))
		ok();
	else
		ko();
	sprintf(rbuffer, "%d", ft_str_is_alpha(t3));
	sprintf(rbuffer2, "%d", str_is_alpha(t3));
	if (!strcmp(rbuffer, rbuffer2))
		ok();
	else
		ko();
	sprintf(rbuffer, "%d", ft_str_is_alpha(t4));
	sprintf(rbuffer2, "%d", str_is_alpha(t4));
	if (!strcmp(rbuffer, rbuffer2))
		ok();
	else
		ko();
	sprintf(rbuffer, "%d", ft_str_is_alpha(t5));
	sprintf(rbuffer2, "%d", str_is_alpha(t5));
	if (!strcmp(rbuffer, rbuffer2))
		ok();
	else
		ko();
	sprintf(rbuffer, "%d", ft_str_is_alpha(t6));
	sprintf(rbuffer2, "%d", str_is_alpha(t6));
	if (!strcmp(rbuffer, rbuffer2))
		ok();
	else
		ko();
	sprintf(rbuffer, "%d", ft_str_is_alpha(t7));
	sprintf(rbuffer2, "%d", str_is_alpha(t7));
	if (!strcmp(rbuffer, rbuffer2))
		ok();
	else
		ko();
	// free(zbuffer);
	// free(zbuffer2);
	write(1, "\n", 1);
#endif

#if STR_ISUPPERCASE
	char e1[] = "NADAAVER";
	char e2[] = "Teste";
	char e3[] = "TeFGHJKL";
	char e4[] = "Teste@";
	char e5[] = "Teste[";
	char e6[] = "Teste\'";
	char e7[] = "Teste{";
	char* ubuffer = malloc(100);
	char* ubuffer2 = malloc(100);

	write(1, "STR_IS_UPPERCASE:", strlen("STR_IS_UPPERCASE:"));
	sprintf(ubuffer, "%d", ft_str_is_alpha(e1));
	sprintf(ubuffer2, "%d", str_is_alpha(e1));
	if (!strcmp(ubuffer, ubuffer2))
		ok();
	else
		ko();
	sprintf(ubuffer, "%d", ft_str_is_alpha(e2));
	sprintf(ubuffer2, "%d", str_is_alpha(e2));
	if (!strcmp(ubuffer, ubuffer2))
		ok();
	else
		ko();
	sprintf(ubuffer, "%d", ft_str_is_alpha(e3));
	sprintf(ubuffer2, "%d", str_is_alpha(e3));
	if (!strcmp(ubuffer, ubuffer2))
		ok();
	else
		ko();
	sprintf(ubuffer, "%d", ft_str_is_alpha(e4));
	sprintf(ubuffer2, "%d", str_is_alpha(e4));
	if (!strcmp(ubuffer, ubuffer2))
		ok();
	else
		ko();
	sprintf(ubuffer, "%d", ft_str_is_alpha(e5));
	sprintf(ubuffer2, "%d", str_is_alpha(e5));
	if (!strcmp(ubuffer, ubuffer2))
		ok();
	else
		ko();
	sprintf(ubuffer, "%d", ft_str_is_alpha(e6));
	sprintf(ubuffer2, "%d", str_is_alpha(e6));
	if (!strcmp(ubuffer, ubuffer2))
		ok();
	else
		ko();
	sprintf(ubuffer, "%d", ft_str_is_alpha(e7));
	sprintf(ubuffer2, "%d", str_is_alpha(e7));
	if (!strcmp(ubuffer, ubuffer2))
		ok();
	else
		ko();
	// free(zbuffer);
	// free(zbuffer2);
	write(1, "\n", 1);
#endif


}
