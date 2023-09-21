#include "custom_shell.h"

/**
 * createPathList - A function that returns a linked list of paths
 * tokenized from the PATH environment variable.
 *
 * Return: A linked list containing the paths extracted
 * from the PATH environment variable.
 */
list_paths *createPathList()
{
	list_paths *pathsList;
	char *copiedPath, *pathVar, *pathToken;

	pathsList = NULL;
	/* Get the PATH environment variable */
	pathVar = _getenv("PATH");
	if (pathVar == NULL)
		return (NULL);
	/* Copy the PATH variable to a new buffer for processing */
	copiedPath = _strdup(pathVar);
	if (copiedPath == NULL)
		return (NULL);
	/* Tokenize the copied PATH variable using ':' delimiter */
	pathToken = strtok(copiedPath, ":");
	while (pathToken != NULL)
	{
		/* Add each tokenized path as a node in the linked list */
		addPathNode(&pathsList, pathToken);
		/* Get the next token */
		pathToken = strtok(NULL, ":");
	}

	free(copiedPath);

	return (pathsList);
}

/**
 * addPathNode - A function adds a new node at the beginning of a linked list.
 * @head: Pointer to the head of the list.
 * @path: Pointer to a path string.
 * Return: The address of the new element, or NULL if it fails.
 */
list_paths *addPathNode(list_paths **head, char *path)
{
	list_paths *newNode;
	int len = 0;
	char *pathCopy;
	/* Calculate the length of the path string */
	while (path[len] != '\0')
	{
		len++;
	}
	/* Allocate memory for the new node */
	newNode = malloc(sizeof(list_paths));

	if (newNode == NULL)
		return (NULL);

	if (path)
	{
		/* Duplicate the path string for the new node */
		pathCopy = _strdup(path);

		if (pathCopy == NULL)
		{
			free(newNode);
			return (NULL);
		}
		/* Update the length and path of the new node */
		newNode->len = len;
		newNode->path = pathCopy;
	}
	else
	{
		newNode->len = 0;
		newNode->path = NULL;
	}
	/* Update the next pointer to point to the current head */
	newNode->next = (*head);
	/* Update the head to the new node */
	*head = newNode;

	return (newNode);
}

/**
 * freePathList - Frees a linked list of paths.
 * @head: Pointer to the head of the list.
 */
void freePathList(list_paths *head)
{
	list_paths *current = head;
	list_paths *nextNode;

	while (current != NULL)
	{
		/* Save a pointer to the next node */
		nextNode = current->next;
		free(current->path);
		free(current);
		/* Move to the next node */
		current = nextNode;
	}
}

/**
 * printPathList - Prints all the elements of a path list.
 * If path is NULL, print [0] (nil).
 * @h: Pointer to the head of the list.
 * Return: The number of nodes.
 */
size_t printPathList(const list_paths *h)
{
	int count = 0;

	if (h == NULL)
	{
		return (0);
	}

	while (h)
	{
		if (h->path == NULL)
		{
			printf("[0] (nil)\n");
			fflush(stdout);
		}
		else
		{
			printf("[%d] %s\n", h->len, h->path);
			fflush(stdout);
		}
		h = h->next;
		count++;
	}

	return (count);
}

