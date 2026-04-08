#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file
 * @text_content: The text to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, const char *text_content)
{
	int fd, len, bytes_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	for (len = 0; text_content[len]; len++)
		;

	bytes_written = write(fd, text_content, len);
	if (bytes_written == -1 || bytes_written != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
