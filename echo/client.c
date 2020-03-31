#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int send_string(int fd){
    int buffer_size = 100;
    for (;;) {
        char buffer[buffer_size];
        int scanned = scanf("%s", buffer);
        if (scanned > 0) {
            write(fd, buffer, buffer_size);
        }
        int read_buffer_size = 100;
        char read_buffer[read_buffer_size];
        int readed = read(fd, read_buffer, read_buffer_size);
        if (readed > 0) {
            printf("%s", read_buffer);
        }
    }
}

int main(int argc, char * argv[]){
    char message[100];
    strcpy(message, argv[1]);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    struct in_addr ip_addr;
    char * ip_str = "127.0.0.1";
    inet_aton(ip_str, &ip_addr);
    addr.sin_family = AF_INET;
    addr.sin_addr = ip_addr;
    addr.sin_port = htons(3000);
    int connected = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
//    char buffer[100];
//    int readed = read(sockfd, buffer, sizeof(buffer));
    send_string(sockfd);
//    while (read(sockfd))
//    printf("%s", buffer);
}