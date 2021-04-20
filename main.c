#include "inc/libasm.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


t_list	*ft_lstnew(void *content)

{

	t_list *node;



	if (!(node = (t_list *)malloc(sizeof(t_list))))

		return (NULL);

	node->next = 0;

	node->content = content;

	return (node);

}

int	main(void)
{
	printf("###\n");
	printf("FT_STRLEN\n");
	printf("###\n");
	printf("\n");
	
	char *s1 = "";
	char *s2 = "abc";
	char *s3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam imperdiet arcu ac tempus congue. Cras maximus vel neque finibus gravida.";

	printf("'%s' -> libasm : %lu\n", s1, ft_strlen(s1));
	printf("'%s' -> libasm : %lu\n", s2, ft_strlen(s2));
	printf("'%s' -> libasm : %lu\n", s3, ft_strlen(s3));

	
	
	printf("\n");
	printf("###\n");
	printf("FT_STRCPY\n");
	printf("###\n");
	printf("\n");
	
	char dest[150];
	char *ss1 = "";
	char *ss2 = "abc";
	char *ss3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam imperdiet arcu ac tempus congue. Cras maximus vel neque finibus gravida.";

	printf("'%s' dest : %s\n", ss1, ft_strcpy(dest, ss1));
	printf("'%s' dest : %s\n", ss2, ft_strcpy(dest, ss2));
	printf("'%s' dest : %s\n", ss3, ft_strcpy(dest, ss3));

	
	
	printf("\n");
	printf("###\n");
	printf("FT_STRCMP\n");
	printf("###\n");
	printf("\n");
	
	printf("'', 'abc' : %d\n", ft_strcmp("", "abc"));
	printf("'abc', '' : %d\n", ft_strcmp("abc", ""));
	printf("'test', 'zest' : %d\n", ft_strcmp("test", "zest"));
	printf("'', '' : %d\n", ft_strcmp("", ""));



	printf("\n");
	printf("###\n");
	printf("FT_WRITE\n");
	printf("###\n");
	printf("\n");
	
	errno = 0;
	printf(" : %d\n", ft_write(1, "abc", 3));
	printf("ERRNO : %s\n", strerror(errno));
	errno = 0;
	printf(" : %d\n", ft_write(15, "abc", 3));
	printf("ERRNO : %s\n", strerror(errno));
	errno = 0;
	printf(" : %d\n", ft_write(1, "", 0));
	printf("ERRNO : %s\n", strerror(errno));
	errno = 0;
	printf(" : %d\n", ft_write(1, "Lorem ipsum dolor", 17));
	printf("ERRNO : %s\n", strerror(errno));



	printf("\n");
	printf("###\n");
	printf("FT_READ\n");
	printf("###\n");
	printf("\n");

	char buff[50];
	int fd;
	int ret;

	buff[49] = 0;
	fd = open("file", O_RDONLY);
	
	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));
	
	errno = 0;
	printf(" : %d\n", ret = ft_read(15, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));
	
	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));
	
	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));

	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));

	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(0, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));



	printf("\n");
	printf("###\n");
	printf("FT_STRDUP\n");
	printf("###\n");
	printf("\n");
	
	char *sss1 = "";
	char *sss2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc eleifend facilisis turpis, id venenatis turpis tristique in. Nullam turpis mauris, ultricies id blandit nec, tincidunt nec ligula.";

	printf("%s\n", ft_strdup(sss1));
	printf("%s\n", ft_strdup(sss2));



	printf("\n");
	printf("###\n");
	printf("LISTS\n");
	printf("###\n");
	printf("\n");
	
	t_list *lst;

	lst = 0;
	ft_list_push_front(&lst, ft_lstnew("a"));
	ft_list_push_front(&lst, ft_lstnew("b"));
	ft_list_push_front(&lst, ft_lstnew("c"));
	ft_list_push_front(&lst, ft_lstnew("d"));
	ft_list_push_front(&lst, ft_lstnew("e"));
	ft_list_push_front(&lst, ft_lstnew("f"));
	ft_list_push_front(&lst, ft_lstnew("g"));

	printf("list size : %d\n", ft_list_size(lst));
	while (lst)
	{
		printf("%s   ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}
