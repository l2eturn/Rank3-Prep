#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdlib.h>
#include <unistd.h>

char *broken_get_next_line(int fd)
{
    char *line = malloc(10000);
    char buff[1];
    int i = 0;
    ssize_t r;

    if (!line)
        return NULL;
    r = read(fd, buff, 1);
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
        r = read(fd, buff, 1);
        if (r < 0) // ตรวจ error ทุกครั้ง
        {
            free(line);
            return NULL;
        }
        if (r == 0) // EOF หลังอ่านบางตัว -> ออก loop แล้วคืนบรรทัดที่มีอยู่
            break;
        // ป้องกัน overflow เล็กน้อย
        if (i >= 9999)
            break;
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