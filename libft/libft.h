/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:10:04 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/23 16:40:39 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//
//-------------------------------DEFINES
//

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

//
//-------------------------------INCLUDES
//

# include "unistd.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>

//
//-------------------------------STRUCTURES
//

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//
//-------------------------------VOID FUNCTIONS
//

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *scr, size_t n);
void				*ft_memmove(void *dest, const void *scr, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				print_char(char c, int *counter);
void				print_str(char *s, int *counter);
void				print_nbr(int n, int *counter);
void				print_unsignednb(unsigned int nb, int *counter);
void				print_pointer(void *ptr, int *counter);
void				print_hex(unsigned int nb, char c, int *counter);
void				free_matrix(void **matrix);
void				sort_matrix(char **matrix);

//
//-------------------------------LONG FUNCTIONS
//

long				ft_atol(const char *str);

//
//-------------------------------INT FUNCTIONS
//

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(char ch);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_lstsize(t_list *lst);
int					ft_printf(const char *str, ...);
int					matrix_size(void **matrix);
int					countword(char const *s, char c);
int					ft_atoh(char *color);
int					str_is_digit(char *str);
int					str_isspace(char *str);
int					ft_strcmp(char *s1, char *s2);

//
//--------------------------------CHAR FUNCTIONS
//

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strcat(char *dest, char *src);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
char				**ft_split_exp(char *str, char delim);
char				**mat_add_field(char **matrix, char *str);
char				**matrix_copy(char **matrix, int size);
char				*gnl_strjoin(char *s1, char *s2);
char				*get_next_line(int fd);
char				*get_cmd_path(char *cmd);
char				*ft_getenv_value(char **mat, char *var_name);
char				*mat_to_str(char **matrix);

//
//--------------------------------SIZE_T FUNCTIONS
//

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

//
//--------------------------------DOUBLE FUNCTIONS
//

double				ft_atod(char *str, int sign, int i, int exp);
#endif
