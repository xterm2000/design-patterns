#ifndef PROTOTYPE_FACTORY_H
#define PROTOTYPE_FACTORY_H

#include <map>
#include <string>

#include "message.h"

using namespace std;

typedef map<const string, Message*> prototype_map_t;

class PrototypeFactory{

  protected:
    PrototypeFactory(){};
    PrototypeFactory( const PrototypeFactory& other );

  public:

    //-----------------------------------------------------------
    PrototypeFactory& get_instance(){
      static PrototypeFactory f;
      return f;
    }

    //-----------------------------------------------------------
    void add_prototype(Const Message* m){
      m_prototypes[m->get_type()] = m;

    }

    //-----------------------------------------------------------
    ~PrototypeFactory(){
      for (prototype_map_t::iterator it = m_prototypes.begin();
          it!=m_prototypes.end();
          ++it)
        delete it->second;
    }

  private:
    prototype_map_t m_prototypes;

};

#endif
