#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if(mkfifo("fifo1", 0777) == -1) {
        if(errno != EEXIST) {
            printf("Nao foi possivel criar o arquivo fifo\n");
            return 1;
        }
    }

    printf("Abrindo...\n");
    int fd = open("fifo1", O_RDWR);
    printf("Aberto\n");
    int x = 97;
    if(write(fd, &x, sizeof(x)) == -1) {
        return 2;
    }
    scanf("%d",&x);
    printf("Escrita concluida\n");
    close(fd);
    printf("Arquivo Fechado\n");
    return 0;
}