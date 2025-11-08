#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *broken_get_next_line(int fd)
{
	char buff[1];
	char *line = malloc(10000);
	int i = 0;
	int r;

	if (!line)
		return NULL;
	r = read(fd,buff,1);
	if (r <= 0)
	{
		free(line);
		return NULL;
	}
	while (r > 0)
	{
		line[i++] = buff[0];
		if (buff[0] == '\n')
			break;
		r = read(fd,buff,1);
	}
	line[i] = '\0';
	return line;
}

#include <stdio.h>
int main(void)
{
	int fd = open("test.txt",O_RDONLY);
	char *line;
	line = broken_get_next_line(fd);
	while (line)
	{
		printf("%s",line);
		free(line);
		line = broken_get_next_line(fd);
	}
	close(fd);
}

//#include <stdlib.h>
//#include <unistd.h>

//char *broken_get_next_line(int fd)
//{
//    char buffer[1024];
//    char *line = malloc(1024);
//    int i = 0;

//    if (!line)
//        return (NULL);

//    while (read(fd, &buffer[i], 1) > 0)
//    {
//        line[i] = buffer[i];
//        if (buffer[i] == '\n')
//        {
//            line[i + 1] = '\0';
//            return (line);
//        }
//        i++;
//    }

//    if (i > 0)
//    {
//        line[i] = '\0';
//        return (line);
//    }

//    free(line);
//    return (NULL);
//}



