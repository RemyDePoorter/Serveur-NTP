#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) //allow user0
{
    char str1[1000];

    printf("Veuillez entrer le nom de l'utilisateur (user0)");
    scanf("%[^\n]", str1); // takes everything before '\n'

    printf("'%s'\n", str1);

    int fd = open("/etc/cron.allow", O_WRONLY | O_CREAT, 0755);

    if (fd == -1)
    {
        printf("Le fichier cron.allow n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    else
    {
        lseek(fd, 409, SEEK_SET); // ajoute user au fichier
        int lenghtName = sizeof(str1) / sizeof(char);
        write(fd, "NTP=", 4);
        
        write(fd, str1, lenghtName);
       
    }
    close(fd);


    return 0;
}