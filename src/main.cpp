#include <iostream>
#include "concrete_builders.h"
#include "log.h"



using namespace std;

int main(int argc, const char* argv[]){

  ConcreteBuiderA b;
  b.add_feature_a();
  b.add_feature_b();
  b.add_feature_c();
  b.add_feature_d();
  LOG_DEBUG( "checking log" );

  return EXIT_SUCCESS;
}

