// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "SubProject.h"

#include "BaseProject.h"

using namespace std;

namespace subproject {

void SubProject::printMsg() {
  std::cout << "SubProject" << endl;
  std::cout << "SubProject can use : ";
  auto* base = CreateBaseProject();
  base->printMsg();
  DestroyBaseProject(base);
}

void SubProject::checkDef() {
#ifdef PRIVATE_BASE_DEF
  std::cout << "PRIVATE_BASE_DEF is defined on SubProject" << std::endl;
#else
  std::cout << "PRIVATE_BASE_DEF is not defined on SubProject" << std::endl;
#endif

#ifdef PUBLIC_BASE_DEF
  std::cout << "PUBLIC_BASE_DEF is defined on SubProject" << std::endl;
#else
  std::cout << "PUBLIC_BASE_DEF is not defined on SubProject" << std::endl;
#endif
}

}  // namespace subproject

subproject::SubProject* CreateSubProject() {
  return new subproject::SubProject();
}

void DestroySubProject(subproject::SubProject* obj) {
  if (obj) {
    delete obj;
    obj = nullptr;
  }
}
