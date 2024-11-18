/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:11:25 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:59:30 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FLAGS		"+ 0-#"
# define NUMBERS		"0123456789"
# define TYPE		"cspdiuxX%"
# define OK	0
# define MALLOC -1337
# define PARSE_ERROR -42
# define BASE_10 10
# define BASE_16 16

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_format
{
	int		left_justified;
	int		plus;
	int		space;
	int		hashtag;
	int		zero;
	char	specifier;
	int		width_value;
	int		precision_value;
}	t_format;

typedef struct s_data
{
	va_list		ap;
	int			chars_written;
	t_format	format;
}	t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t num);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_tolower(int c);
void	*ft_memset(void *s, int value, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t num);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int value, size_t num);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		check(const char *s, char c);
void	fill_space(t_data *data, const char c, int size);
int		ft_printf(const char *format, ...);
void	ft_printf_add(t_data *data, void *address);
void	ft_printf_char(t_data *data, int c);
void	ft_printf_hex(t_data *data, unsigned int nbr);
void	ft_printf_int(t_data *data, int nbr);
void	ft_printf_unint(t_data *data, unsigned int nbr);
int		format_parsing(t_data *data, const char **format);
int		hex_length(unsigned long long n);
int		numlen(long long nbr);
void	print_hex(t_data *data, unsigned long long nbr);
void	print_nbr(t_data *data, long long nbr);
void	print_prec_zero_d(t_data *data, int precision);
void	print_prec_zero(t_data *data);
void	print_str(t_data *data, const char *str);
void	struct_unint_zero(t_data *data, unsigned int nbr);
void	sign_space(t_data *data, long long nbr);
int		string_print(t_data *data, const char *str, int precision);
void	str_null(t_data *data);
int		write_print(t_data *data, int c);
void	zero_space(t_data *data, int size);
void	zero_space_sign(t_data *data, int size, int nbr);
void	struct_str_null(t_data *data);
void	struct_str_empty(t_data *data);

#endif
