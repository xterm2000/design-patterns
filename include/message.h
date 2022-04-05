#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
using namespace std;

// Message interface 
class Message{
  public:
    virtual ~Message() {};
    virtual Message* clone() const  = 0;
    virtual void set(const string& s1) = 0;
    virtual void print() = 0;
};
#endif
