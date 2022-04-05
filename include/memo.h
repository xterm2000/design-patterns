#ifndef MEMO_H
#define MEMO_H

#include "message.h"

class Memo: public Message{

  private:
    int m_number;
    char* m_image;
  public:
    ~Memo(){}
    Memo () :m_number(0){}
    void set(const string& s1);
    void print();
    Message* clone() const { return new Memo(*this); }
    virtual string get_type() { return "Memo" };


};

#endif

