#include "BaseProject.h"
#include "SubProject.h"

using namespace std;

int main() {
  auto* base = CreateBaseProject();
  base->printMsg();
  base->checkDef();
  DestroyBaseProject(base);
  cout << endl;

  auto* sub = CreateSubProject();
  sub->printMsg();
  sub->checkDef();
  DestroySubProject(sub);
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
