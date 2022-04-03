#ifndef BUILDER_H
#define BUILDER_H

class Builder {
  private:
    int id = 0;
  public:
    virtual void add_feature_a() = 0;
    virtual void add_feature_b() = 0;
    virtual void add_feature_c() = 0;
    virtual void add_feature_d() = 0; 
};

#endif
