#!/bin/zsh

N=0

if [ -f ex00/ft_strcpy.c ]
then
  STRCPY=ex00/ft_strcpy.c
  ((N=N+1))
  DEFINE_STRCPY="-D STRCPY"
fi

if [ -f ex01/ft_strncpy.c ]
then
  STRNCPY=ex01/ft_strncpy.c
  ((N=N+1))
  DEFINE_STRNCPY="-D STRNCPY"
fi

if [ -f ex02/ft_str_is_alpha.c ]
then
  STR_ISALPHA=ex02/ft_str_is_alpha.c
  ((N=N+1))
  DEFINE_STR_ISALPHA="-D STR_ISALPHA"
fi

if [ -f ex03/ft_str_is_numeric.c ]
then
  STR_ISNUMERIC=ex03/ft_str_is_numeric.c
  ((N=N+1))
  DEFINE_STR_ISNUMERIC="-D STR_ISNUMERIC"
fi

if [ -f ex04/ft_str_is_lowercase.c ]
then
  STR_ISLOWERCASE=ex04/ft_str_is_lowercase.c
  ((N=N+1))
  DEFINE_STR_ISLOWERCASE="-D STR_ISLOWERCASE"
fi

if [ -f ex05/ft_str_is_uppercase.c ]
then
  STR_ISUPPERCASE=ex05/ft_str_is_uppercase.c
  ((N=N+1))
  DEFINE_STR_ISUPPERCASE="-D STR_ISUPPERCASE"
fi

if test $N -eq 0
then
  echo "Please put tester's files in day_03 folder"
  exit
fi

gcc -Wall -Wextra -Werror ${DEFINE_STRCPY} ${DEFINE_STRNCPY} ${DEFINE_STR_ISALPHA} ${DEFINE_STR_ISNUMERIC} ${DEFINE_STR_ISLOWERCASE} ${DEFINE_STR_ISUPPERCASE}  \
main.c "${STRCPY}" "${STRNCPY}" "${STR_ISALPHA}" "${STR_ISNUMERIC}" "${STR_ISLOWERCASE}" "${STR_ISUPPERCASE}"

./a.out