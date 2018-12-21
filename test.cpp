#include "DataReaderServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include <map>

using namespace std;

std::map<std::string, double> dataReceived;

dataReceived["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
dataReceived["/instrumentation/altimeter/indicated-altitude-ft"] = 0;
dataReceived["/instrumentation/altimeter/pressure-alt-ft"] = 0;
dataReceived["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 0;
dataReceived["/instrumentation/attitude-indicator/indicated-roll-deg"] = 0;
dataReceived["/instrumentation/attitude-indicator/internal-pitch-deg"] = 0;
dataReceived["/instrumentation/attitude-indicator/internal-roll-deg"] = 0;
dataReceived["/instrumentation/encoder/indicated-altitude-ft"] = 0;
dataReceived["/instrumentation/encoder/pressure-alt-ft"] = 0;
dataReceived["/instrumentation/gps/indicated-altitude-ft"] = 0;
dataReceived["/instrumentation/gps/indicated-ground-speed-kt"] = 0;
dataReceived["/instrumentation/gps/indicated-vertical-speed"] = 0;
dataReceived["/instrumentation/heading-indicator/indicated-heading-deg"] = 0;
dataReceived["instrumentation/magnetic-compass/indicated-heading-deg"] = 0;
dataReceived["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 0;
dataReceived["/instrumentation/turn-indicator/indicated-turn-rate"] = 0;
dataReceived["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 0;
dataReceived["/controls/flight/aileron"] = 0;
dataReceived["/controls/flight/elevator"] = 0;
dataReceived["/controls/flight/rudder"] = 0;
dataReceived["/controls/flight/flaps"] = 0;
dataReceived["/controls/engines/engine/throttle"] = 0;
dataReceived["/engines/engine/rpm"] = 0;


int main() {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    string current;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    map <string, string> properties;


    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    } else {
        cout << "Socket !" << endl;
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5400;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    } else {
        cout << "Binded !" << endl;
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
    } else {
        cout << "Accepted !" << endl;
    }

    /* If connection is established then start communicating */
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    map<string, double>::iterator itr = dataReceived.begin();
    int i = 0;
    while (n >= 0) {
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        current = buffer[0];
        for (i = 1; buffer[i] != ','; i++) {
            current += buffer[i];
        }
        itr->second = std::stod(current);
        ++itr;
        while (1) {
            i++;
            current = buffer[i];
            for (++i; buffer[i] != ','; i++) {
                current += buffer[i];
            }
            itr->second = std::stod(current);
            if (itr == dataReceived.end()) { break; }
            ++itr;
        }
        n = read(newsockfd, buffer, 255);
    }
}