#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(char fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
