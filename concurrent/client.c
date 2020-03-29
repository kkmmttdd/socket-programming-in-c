#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

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
    char buffer[100];
    int readed = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
}