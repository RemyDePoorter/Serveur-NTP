#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("/etc/chrony.conf", O_WRONLY | O_CREAT, 0755);

    if (fd == -1)
    {
        printf("Le fichier chrony.conf n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    else
    {
        lseek(fd, 496, SEEK_SET); // comment rtcsync
        write(fd, "#", 1);

        lseek(fd, 223, SEEK_CUR); // enable ntp on local network
        write(fd, "allow 10.0.255.0/24", 19);

        lseek(fd, 60, SEEK_CUR); // add local stratum
        write(fd, "local stratum 10", 56);
    }

    close(fd);

    return 0;
}