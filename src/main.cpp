#include <iostream>
#include <cmath>
#include <map>
#include "graph.h"
#include "concrete_builders.h"
#include "log.h"

#include "message.h"


#include "mail.h"
#include "memo.h"
#include "fax.h"



#include "abstract_factory.h"

using namespace std;

typedef AbstractFactory<string,Message> Factory_T;
template class AbstractFactory<string, Message>;

void test_builder() {

  ConcreteBuiderA b;
  b.add_feature_a();
  b.add_feature_b();
  b.add_feature_c();
  b.add_feature_d();
  LOG_DEBUG( "checking log" );
}
void DFS_test(){
  Graph g;
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);
  g.addEdge(1,4);
  g.addEdge(4,4);
  g.addEdge(5,5);
  g.addEdge(4,5);
  g.DFS(0);
}

int test (int n , int k){

  int a = n;
  while (a>0){
    cout<<a%2;
    a= a>>1 ;
  }

  unsigned int b;

  b = n >> k;
  cout<<"--"<<k%2<<endl;
  return n + pow(2,k-1);
}

int main(int argc, const char* argv[]){

  Message* mm = new Memo();

 int* b = NULL;
  Factory_T::get_instance().add_prototype("Memo",mm);
  Factory_T::get_instance().add_prototype("Memo",mm);
  Factory_T::get_instance().add_prototype("Memo",mm);
    try {
      Message* m = Factory_T::get_instance().create_object("Memo");
      m->print();
      delete m;
      m= Factory_T::get_instance().create_object("Fax");
      cout<<m<<endl;
    } catch (...){
      cout<<"exception"<<endl;

    }
  return EXIT_SUCCESS;

}

