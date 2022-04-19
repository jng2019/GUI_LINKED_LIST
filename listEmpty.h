#ifndef LISTEMPTY_H
#define LISTEMPTY_H


#include <string>

using namespace std;

class ListEmpty
{
private:
    string message;
public:
    ListEmpty()
    {
        message = "List is empty!!";
    }
    string what()
    {
        return message;
    }
};

#endif // LISTEMPTY_H
