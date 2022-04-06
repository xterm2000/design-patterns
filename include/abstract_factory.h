#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <map>
#include <string>

#include "message.h"

using namespace std;


template <class Key, class Object>
class AbstractFactory{

  public:

    //-----------------------------------------------------------
    AbstractFactory& get_instance(){
      static AbstractFactory f;
      return f;
    }

    //-----------------------------------------------------------
    Object* create_object(const Key &key){
      return m_prototypes[key]->clone();
    }

    //-----------------------------------------------------------
    void add_prototype( const Key key, const Object *proto ){
      m_prototypes[key] = proto;
    }

    //-----------------------------------------------------------
    ~AbstractFactory(){
      for (map <const Key, const Object*>::iterator it = m_prototypes.begin();
	  it!=m_prototypes.end();
	  ++it)
	delete it->second;
    }

  private:
    map <const Key, const Object*> m_prototypes;
    // 
    AbstractFactory(){};
    AbstractFactory( const AbstractFactory& other );
    AbstractFactory& operator=(const AbstractFactory&);

};

#endif
