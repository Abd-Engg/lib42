#include "libft.h"
void *f(void *content)
{
	unsigned char *s = content;
	int i=0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return content;
}
void del(void *s)
{
	(void)s; 
	return;
}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*head;
	t_list	*new;
	void	*content;

	if (!lst || !f)
		return (NULL);
	current = lst;
	head = NULL;
	while (current != NULL)
	{
		content = f(current->content);
		new = ft_lstnew(content);
		if (!new)
		{
			if (del)
				del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		current = current->next;
	}
	return (head);
}
#include <stdio.h>
int main()
{

	t_list *head = ft_lstnew(ft_strdup("malkawi"));
	t_list *n2 = ft_lstnew(ft_strdup("abd"));
	t_list *n3 = ft_lstnew(ft_strdup("ali"));
	t_list *n4 = ft_lstnew(ft_strdup("mohammad"));

	ft_lstadd_back(&head,n2);
	ft_lstadd_back(&head,n3);
	ft_lstadd_back(&head,n4);

	t_list *new_list = ft_lstmap(head , f , del);

	while (new_list != NULL)
	{
		printf("%s\n",(char *)new_list->content);
		new_list = new_list->next;
	}
	
}