#include "director.h"

void Director::set_builder(Builder* b){
  this->builder = b;
}

void Director::build_min_product(){
  builder->add_feature_a();
  builder->add_feature_b();
}

void Director::build_max_product(){

  builder->add_feature_a();
  builder->add_feature_b();
  builder->add_feature_c();
  builder->add_feature_d();
}
