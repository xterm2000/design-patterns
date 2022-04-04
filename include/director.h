#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"

class Director {
  private: 
    Builder* builder;
  public:
    void set_builder(Builder* b);
    void build_min_product();
    void build_max_product();

};

#endif
