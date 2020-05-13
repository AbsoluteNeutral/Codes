
#include "string.h"
#include <string>

int main()
{
  zg::string a{"asada"};
	
	std::cout << a << std::endl;
	a = "abcdefghijkl";
  std::cout << a << std::endl;
  std::cout << a.size() << std::endl;
  std::cout << a.length() << std::endl;
	
	
	try
	{
		std::cout << a.at(1) << std::endl;
		//std::cout << a.at(-1) << std::endl;
		//std::cout << a.at(8) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}
	a.clear();
	std::cout << a.front() << std::endl;
	std::cout << a.back() << std::endl;
}