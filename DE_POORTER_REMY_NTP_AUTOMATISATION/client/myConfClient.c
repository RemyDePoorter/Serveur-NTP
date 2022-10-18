#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char str1[1000];

    printf("Veuillez entrer l'ip du serveur (10.0.255.numPC/24)");
    scanf("%[^\n]", str1); // takes everything before '\n'

    printf("'%s'\n", str1);

    int fd = open("/etc/systemd/timesyncd.conf", O_WRONLY | O_CREAT, 0755);

    if (fd == -1)
    {
        printf("Le fichier timesyncd.conf n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    else
    {
        lseek(fd, 409, SEEK_SET); // ajoute NTP=10.0.255.numPC/24
        int lenghtIp = sizeof(str1) / sizeof(int);
        write(fd, "NTP=", 4);
        
        write(fd, str1, lenghtIp);
       
    }
    close(fd);
    return 0;
}