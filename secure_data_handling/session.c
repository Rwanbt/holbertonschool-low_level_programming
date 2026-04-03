#include <stdlib.h>
#include <string.h>
#include "session.h"
/**
 * _strdup - Custom implementation of strdup for gnu89 compatibility
 * @s: string to duplicate
 * Return: pointer to new string or NULL
 */
static char *_strdup(const char *s)
{
	char *dup;
	size_t len;

	if (!s)
		return (NULL);
	len = strlen(s) + 1;
	dup = (char *)malloc(len);
	if (dup)
		memcpy(dup, s, len);
	return (dup);
}

session_t *session_create(const char *id, unsigned int uid, const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id)
		return (NULL);

	s = (session_t *)malloc(sizeof(*s));
	if (!s)
		return NULL;

	s->id = _strdup(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;

	if (data_len > 0)
	{
		s->data = (unsigned char *)malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return NULL;
		}
		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}
	 else
	{
		s->data = NULL;
		s->data_len = 0;
	}

	return s;
}

int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *tmp;

	if (!s)
		return 0;

	if (data_len == 0)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	tmp = (unsigned char *)realloc(s->data, data_len);
	if (!tmp)
		return (0);

	s->data = tmp;
	if (data)
		memcpy(s->data, data, data_len);
	s->data_len = data_len;
	return (1);
}

void session_destroy(session_t *s)
{
	if (!s)
		return;

	if (s->id)
		free(s->id);

	if (s->data)
	free(s->data);

	free(s);
}
