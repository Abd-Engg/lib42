#include "libft.h"

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
