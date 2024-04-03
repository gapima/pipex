
#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

size_t	ft_strlen(const char *s);
size_t	ft_putstr(char *s);
size_t	ft_itoa_base(long nbr, const char *base);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_printf(const char *s, ...);
int		ft_print_point(long nbr, const char *base);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(char *s, int c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif