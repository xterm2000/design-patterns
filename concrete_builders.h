#ifndef CONCRETE_BUILDER_H
#define CONCRETE_BUILDER_H

#include "builder.h"

class ConcreteBuiderA : public Builder{

  public:

    void add_feature_a();
    void add_feature_b();
    void add_feature_c();
    void add_feature_d(); 
  private:
    const char * name = "ConcreteBuiderA";
};

#endif
