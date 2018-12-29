#include "openServerCommand.h"

using namespace std;

openServerCommand::openServerCommand(std::map<std::string, double> *symbolTable,
                                     std::map<std::string, std::string> *varAddresses) : symbolTable(symbolTable),
                                     varAddresses(varAddresses){
    data = new DataReaderServer();
}

int openServerCommand::execute(std::string order[], int index) {
    waitingServer(stoi(order[index+1]));
    thread thread1(&DataReaderServer::execution, data, symbolTable, varAddresses, stoi(order[index+1]));
    thread1.detach();
    return 3;
}

void openServerCommand::waitingServer(int port) {
    cout << "Waiting for connection from simulator" << endl;
    int sockfd, newsockfd, portno, clilen;
    char buffer[350];
    string current;
    struct sockaddr_in serv_addr, cli_addr;
    int n;


    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer, 350);
    n = read(newsockfd, buffer, 349);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
}