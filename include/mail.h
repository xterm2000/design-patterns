#ifndef MAIL_H
#define MAIL_H

#include "message.h"

class Mail: public Message{

  private:
    int m_number;
    char* m_image;
  public:
    ~Mail(){}
    Mail () :m_number(0){}
    void set(const string& s1);
    void print();
    Message* clone() const { return new Mail(*this); }


};

#endif

