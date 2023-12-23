#include "BaseProject.h"
#include "SubProject.h"

using namespace std;

int main() {
  baseproject::BaseProject base;
  base.printMsg();
  base.checkDef();
  cout << endl;

  subproject::SubProject sub;
  sub.printMsg();
  sub.checkDef();
  cout << endl;

#ifdef PRIVATE_BASE_DEF
  std::cout << "PRIVATE_BASE_DEF is defined on MainProject" << std::endl;
#else
  std::cout << "PRIVATE_BASE_DEF is not defined on MainProject" << std::endl;
#endif

#ifdef PUBLIC_BASE_DEF
  std::cout << "PUBLIC_BASE_DEF is defined on MainProject" << std::endl;
#else
  std::cout << "PUBLIC_BASE_DEF is not defined on MainProject" << std::endl;
#endif

  return 0;
}
