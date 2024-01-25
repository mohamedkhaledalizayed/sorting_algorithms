#include "sort.h"

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
/**
 *  cocktail_sort_list - sort function
 * @list: the header of the linked list
 * Return: no return value
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *item;
	int changes = 1;

	if (!list || !*list)
		return;
	item = *list;
	while (changes)
	{
		changes = 0;
		while ((item != NULL) && (item->next != NULL))
		{
			if (item->n > item->next->n)
			{
				swap(item->next, item);
				print_list(*list);
				changes = 1;
			}
			item = item->next;
		}

		while ((item != NULL) && (item->prev != NULL))
		{
			if (item->n < item->prev->n)
			{
				swap(item, item->prev);
				print_list(*list);
				changes = 1;
			}
			item = item->prev;
		}
	}
}
