#include "sort.h"
/**
 * insertion_sort_list - sort function
 * @list: the header of the linked list
 * Return: no return value
*/
void insertion_sort_list(listint_t **list)
{
	/*loop over the linked_list*/
	listint_t *item, *item2;

	if ((list && *list))
	{
		item = *list;
		while (item)
		{
			item2 = item;
			item = item->next;
			while (item2 && item2->prev)
			{
				if (item2->n < item2->prev->n)
				{
					swap(item2, item2->prev);
					if (!item2->prev)
						*list = item2;
					print_list(*list);
				}
				else
					break;
			}
		}
	}
}
/**
 * swap - function to swap the nods of the linked list
 * @element: the first node
 * @element2: the last
 * Return: no return value
*/
void swap(listint_t *element, listint_t *element2)
{
	/*declaer temps*/
	listint_t *temp_next, *temp_prev;

	if (!element || !element2)
		return;

	if (element->next)
		element->next->prev = element2;

	if (element2->prev)
		element2->prev->next = element;
	/*assuin temps by the element prev,next*/
	temp_prev = element2->prev;
	temp_next = element->next;
	/*make the change in the links */
	element2->prev = element;
	element->next = element2;
	element->prev = temp_prev;
	element2->next = temp_next;

}
