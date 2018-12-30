using namespace std;
#include "sleepCommand.h"
/* this will execute sleep(time) command*/
int sleepCommand::execute(std::string *commands, int startIndex) {
    cout << "Current command" << commands[startIndex] << " ";
    cout << "Sleep time " << commands[startIndex+1] << endl;
    int sleepTime = stoi(commands[startIndex+1]);
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    return 2;
}