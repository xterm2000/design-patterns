#ifndef FAX_H
#define FAX_H

#include "message.h"

class Fax: public Message{

  private:
    int m_number;
    char* m_image;
  public:
    ~Fax(){}
    Fax () :m_number(0){}
    void set(const string& s1);
    void print();
    Message* clone() const { return new Fax(*this); }
    virtual string get_type() { return "Fax"; };


};

#endif

