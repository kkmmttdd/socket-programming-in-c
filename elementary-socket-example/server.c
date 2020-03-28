#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
//    receive ip address
    char ip_address_string[100];
    strcpy(ip_address_string, argv[1]);
//    set sock_addr_in structure
    struct in_addr target_in_addr;
    inet_aton(ip_address_string, &target_in_addr);
    struct sockaddr_in addr, client_addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3000);
    addr.sin_addr = target_in_addr;
//    initialize socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    bind socket
    bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    printf("ip addres: %s\n", inet_ntoa(addr.sin_addr));
    printf("port : %d\n", ntohs(addr.sin_port));
//    listen
    listen(sock, 3);
//    accept request
    socklen_t socket_length;
    int server_socket = accept(sock,(struct sockaddr *) &client_addr, &socket_length);
    char message[100];
    strcpy(message, "server message");
    write(server_socket, message, sizeof(message));
    char buffer[10];
    read(server_socket, buffer, sizeof(buffer));
    printf("%s", buffer);
}