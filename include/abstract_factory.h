#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <map>
#include <string>

#include "message.h"

using namespace std;


template <class T, class Object>
class AbstractFactory{

  public:

    //-----------------------------------------------------------
    static AbstractFactory& get_instance(){
      static AbstractFactory f;
      return f;
    }

    //-----------------------------------------------------------
    Object* create_object(const T &key){

      auto it = m_prototypes.find(key);

      if (it == m_prototypes.end())
        return nullptr;
      else
        return m_prototypes[key]->clone();
    }

    //-----------------------------------------------------------
    void add_prototype( const T &key, const Object *proto ){
      m_prototypes[key] = proto;
    }

    //-----------------------------------------------------------
    ~AbstractFactory(){
      // remove the mappings 
      for ( auto it = m_prototypes.begin();
          it != m_prototypes.end();
          ++it)
        delete it->second;
    }

  private:
    map < const T, const Object * > m_prototypes;
    //  hidden ctors 
    AbstractFactory(){};
    AbstractFactory( const AbstractFactory& other );
    AbstractFactory& operator=(const AbstractFactory&);

};

#endif
