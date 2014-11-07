#include <iostream>

#include <rafl/examples/ExampleReservoir.h>
using namespace rafl;

#include <rafl/DecisionTree.h>
using namespace rafl;
using namespace tvgutil;

int main()
{
  unsigned int seed = 0;
  ExampleReservoir reservoir(10, RandomNumberGenerator_Ptr(new RandomNumberGenerator(seed)));
  for(int i = 0; i < 20; ++i)
  {
    reservoir.add_example(i);
    std::cout << reservoir << '\n';
  }
  //DecisionTree<int> dt(boost::shared_ptr<std::map<int,Example<int> > >(), 10, RandomNumberGenerator_Ptr(new RandomNumberGenerator(seed)));
  return 0;
}
