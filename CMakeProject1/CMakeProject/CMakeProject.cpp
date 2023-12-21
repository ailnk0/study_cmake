// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject.h"

#include "CMakeRoot/CMakeRoot.h"

using namespace std;

int main() {
  cmakeroot::CMakeRoot root;
  root.printMsg();

  return 0;
}
