#include "bitset.h"

namespace zg{

}

using namespace zg;
int main()
{
  Print_BuiltInTypeSize();
  
  printf("\n");
  
  printf("unsigned: %s\n", ConvertToBinary(10).c_str());
  printf("int:      %s\n", ConvertToBinary(-10).c_str());
  printf("float:    %s\n", ConvertToBinary(10.0f).c_str());
  printf("-float:   %s\n", ConvertToBinary(-10.0f).c_str());
  
  printf("unsigned: %s\n", ConvertToHex(10).c_str());
  printf("int:      %s\n", ConvertToHex(-10).c_str());
  printf("float:    %s\n", ConvertToHex(10.0f).c_str());
  printf("-float:   %s\n", ConvertToHex(-10.0f).c_str());
}
