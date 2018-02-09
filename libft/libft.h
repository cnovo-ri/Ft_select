/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:20:36 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/01/17 05:08:21 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <math.h>
# include <termios.h>
# include <term.h>
//# include <curses.h>
# include <signal.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <stdarg.h>

# define RVIDEO		"\033[7m"
# define UNDERLINE	"\033[4m"
# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define PURPLE		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define GREY		"\033[1;37m"
# define NORMAL		"\033[0m"

# define BUFF_SIZE 4096

typedef struct		s_struct
{
	char			*s[5000];
	int				r;
	char			buf[BUFF_SIZE + 1];
	char			*t;
	char			*t_b;
}					t_struct;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(int const fd, char **line);
int					ft_sqrt(int nb);
int					ft_swap(int *a, int *b);
int					ft_count_words(const char *s, char c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strcapitalize(char *str);
int					ft_isxdigit(int c);
int					ft_isspace(int c);
int					ft_isgraph(int c);
int					ft_iscntrl(int c);
int					ft_isblank(int c);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_strtrim(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strmap(const char *s, char (*f)(char));
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
void				ft_strclr(char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strnew(size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strdel(char **as);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_putchar(char c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strstr(const char *big, const char *little);
int					ft_islower(int c);
int					ft_isupper(int c);
char				*ft_strcpy(char *dst, const char *src);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
char				*ft_strdup(const char *s1);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putnbr(int n);
int					ft_atoi(const char *str);
int					ft_tolower(int c);
void				ft_putstr(const char *s);
void				ft_putnbr(int n);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);

#endif
