#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) //add task to crontab
{
    // Create file remy.txt
     int fd1 = open("/etc/remy.txt", O_WRONLY | O_CREAT, 0777);

    if (fd1 == -1)
    {
        printf("Le fichier remy.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    close(fd1);

    //edit crontab

    int fd = open("/etc/crontab", O_WRONLY | O_CREAT, 0755);

    if (fd == -1)
    {
        printf("Le fichier cron.allow n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    else
    {
        write(fd, "*/1 * * * * echo “coucou” >> remy.txt", 4);
          
    }
    close(fd);
    return 0;
}