#include "DataReaderServer.h"


using namespace std;

DataReaderServer::DataReaderServer(std::mutex* m) : m(m) {
    dataReceived["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
    insertOrder.push_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
    dataReceived["/instrumentation/altimeter/indicated-altitude-ft"] = 0;
    insertOrder.push_back("/instrumentation/altimeter/indicated-altitude-ft");
    dataReceived["/instrumentation/altimeter/pressure-alt-ft"] = 0;
    insertOrder.push_back("/instrumentation/altimeter/pressure-alt-ft");
    dataReceived["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 0;
    insertOrder.push_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
    dataReceived["/instrumentation/attitude-indicator/indicated-roll-deg"] = 0;
    insertOrder.push_back("/instrumentation/attitude-indicator/indicated-roll-deg");
    dataReceived["/instrumentation/attitude-indicator/internal-pitch-deg"] = 0;
    insertOrder.push_back("/instrumentation/attitude-indicator/internal-pitch-deg");
    dataReceived["/instrumentation/attitude-indicator/internal-roll-deg"] = 0;
    insertOrder.push_back("/instrumentation/attitude-indicator/internal-roll-deg");
    dataReceived["/instrumentation/encoder/indicated-altitude-ft"] = 0;
    insertOrder.push_back("/instrumentation/encoder/indicated-altitude-ft");
    dataReceived["/instrumentation/encoder/pressure-alt-ft"] = 0;
    insertOrder.push_back("instrumentation/encoder/pressure-alt-ft");
    dataReceived["/instrumentation/gps/indicated-altitude-ft"] = 0;
    insertOrder.push_back("/instrumentation/gps/indicated-altitude-ft");
    dataReceived["/instrumentation/gps/indicated-ground-speed-kt"] = 0;
    insertOrder.push_back("/instrumentation/gps/indicated-ground-speed-kt");
    dataReceived["/instrumentation/gps/indicated-vertical-speed"] = 0;
    insertOrder.push_back("/instrumentation/gps/indicated-vertical-speed");
    dataReceived["/instrumentation/heading-indicator/indicated-heading-deg"] = 0;
    insertOrder.push_back("/instrumentation/heading-indicator/indicated-heading-deg");
    dataReceived["instrumentation/magnetic-compass/indicated-heading-deg"] = 0;
    insertOrder.push_back("instrumentation/magnetic-compass/indicated-heading-deg");
    dataReceived["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 0;
    insertOrder.push_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
    dataReceived["/instrumentation/turn-indicator/indicated-turn-rate"] = 0;
    insertOrder.push_back("/instrumentation/turn-indicator/indicated-turn-rate");
    dataReceived["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 0;
    insertOrder.push_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    dataReceived["/controls/flight/aileron"] = 0;
    insertOrder.push_back("/controls/flight/aileron");
    dataReceived["/controls/flight/elevator"] = 0;
    insertOrder.push_back("/controls/flight/elevator");
    dataReceived["/controls/flight/rudder"] = 0;
    insertOrder.push_back("/controls/flight/rudder");
    dataReceived["/controls/flight/flaps"] = 0;
    insertOrder.push_back("/controls/flight/flaps");
    dataReceived["/controls/engines/engine/throttle"] = 0;
    insertOrder.push_back("/controls/engines/engine/throttle");
    dataReceived["/engines/engine/rpm"] = 0;
    insertOrder.push_back("/engines/engine/rpm");
}


void DataReaderServer::execution(std::map<std::string, double> *symbolTable,
                                 std::map<std::string, std::string> *varAddresses,int port) {
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
    sleep(15000);
    int j = 0;
    int i = 0;
    while (n >= 0) {
        m->lock();
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        j = 0;
        i = 0;
        current = buffer[0];
        for (i = 1; buffer[i] != ','; i++) {
            current += buffer[i];
        }
        dataReceived[insertOrder[0]] = std::stod(current);
        i++;
        while(buffer [i] != '\0') {
            const std::string &s = insertOrder[j];
            current = buffer[i];
            i++;
            for ( ; (buffer[i] != ',') && (buffer [i] != '\0'); i++) {
                current += buffer[i];
            }
            dataReceived[insertOrder[j]] = std::stod(current);
            j++;
            i++;
        }
        m->unlock();
        actualizeData(symbolTable, varAddresses);
        n = read(newsockfd, buffer, 349);
    }
}

void DataReaderServer::actualizeData(std::map<std::string, double> *symbolTable,
                                     std::map<std::string, std::string> *varAddresses) {

    for (auto itr = dataReceived.begin() ; itr != dataReceived.end() ; ++itr) {
        auto iter = (*varAddresses).find(itr->first);
        if (iter != (*varAddresses).end()) {
            (*symbolTable)[(*varAddresses)[itr->first]] = itr->second;
        }
    }
}