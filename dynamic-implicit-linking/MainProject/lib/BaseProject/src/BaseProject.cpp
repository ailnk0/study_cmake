// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "BaseProject.h"

using namespace std;

namespace baseproject {

void BaseProject::printMsg() { std::cout << "BaseProject" << std::endl; }

void BaseProject::checkDef() {
#ifdef PRIVATE_BASE_DEF
  std::cout << "PRIVATE_BASE_DEF is defined on BaseProject" << std::endl;
#else
  std::cout << "PRIVATE_BASE_DEF is not defined on BaseProject" << std::endl;
#endif

#ifdef PUBLIC_BASE_DEF
  std::cout << "PUBLIC_BASE_DEF is defined on BaseProject" << std::endl;
#else
  std::cout << "PUBLIC_BASE_DEF is not defined on BaseProject" << std::endl;
#endif
}

}  // namespace baseproject

baseproject::BaseProject* CreateBaseProject() {
  return new baseproject::BaseProject();
}

void DestroyBaseProject(baseproject::BaseProject* baseProject) {
  if (baseProject) {
    delete baseProject;
    baseProject = nullptr;
  }
}
