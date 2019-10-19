
#include "bitset.h"

namespace zg{

  void ztest_bitset()
  {
    printf(" ############################## Running ztest_bitset.cpp... ############################## \n\n");
    Print_BuiltInTypeSize();
    printf("\n");
    
    {
      zg::Bitset<10>  test0{10};
      zg::Bitset<32>  test1{-10};
      zg::Bitset<64>  test2{long(-10)};
      zg::Bitset<64>  test3{-10};
      zg::Bitset<200> test4{10};
      zg::Bitset<100> test5{10.0f};
      zg::Bitset<100> test6{-10.0f};
      zg::Bitset<100> test7{10.0};
      zg::Bitset<100> test8{-10.0};
    
      std::cout << "Bitset test:" << std::endl;
      std::cout << "test0 \n" << test0 << std::endl;
      std::cout << "test1 \n" << test1 << std::endl;
      std::cout << "test2 \n" << test2 << std::endl;
      std::cout << "test3 \n" << test3 << std::endl;
      std::cout << "test4 \n" << test4 << std::endl;
      std::cout << "test5 \n" << test5 << std::endl;
      std::cout << "test6 \n" << test6 << std::endl;
      std::cout << "test7 \n" << test7 << std::endl;
      std::cout << "test8 \n" << test8 << std::endl;
      std::cout << std::endl;
    }
    
    {
      zg::TriBitset<10>  test0{10};
      zg::TriBitset<32>  test1{-10};
      zg::TriBitset<64>  test2{long(-10)};
      zg::TriBitset<64>  test3{-10};
      zg::TriBitset<200> test4{10};
      zg::TriBitset<100> test5{10.0f};
      zg::TriBitset<100> test6{-10.0f};
      zg::TriBitset<100> test7{10.0};
      zg::TriBitset<100> test8{-10.0};
    
      std::cout << "TriBitset test:" << std::endl;
      std::cout << "test0 \n" << test0 << std::endl;
      std::cout << "test1 \n" << test1 << std::endl;
      std::cout << "test2 \n" << test2 << std::endl;
      std::cout << "test3 \n" << test3 << std::endl;
      std::cout << "test4 \n" << test4 << std::endl;
      std::cout << "test5 \n" << test5 << std::endl;
      std::cout << "test6 \n" << test6 << std::endl;
      std::cout << "test7 \n" << test7 << std::endl;
      std::cout << "test8 \n" << test8 << std::endl;
      std::cout << std::endl;
    }
    
    
    printf("\n");
    
    printf("unsigned:      %u\n", ConvertToDecimal<unsigned>(ConvertToBinary(10).c_str()));
    printf("int:           %d\n", ConvertToDecimal<int>(ConvertToBinary(-10).c_str()));
    printf("float:         %f\n", ConvertToDecimal<float>(ConvertToBinary(10.0f).c_str()));
    printf("-float:        %f\n", ConvertToDecimal<float>(ConvertToBinary(-10.0f).c_str()));
    printf("unsigned long: %lu\n", ConvertToDecimal<unsigned long>(ConvertToBinary(long(10)).c_str()));
    printf("long:          %ld\n", ConvertToDecimal<long>(ConvertToBinary(long(-10)).c_str()));
    printf("double:        %f\n", ConvertToDecimal<double>(ConvertToBinary(10.0).c_str()));
    printf("-double:       %f\n", ConvertToDecimal<double>(ConvertToBinary(-10.0).c_str()));
    
    printf("unsigned:      %s\n", ConvertToBinary(10).c_str());
    printf("int:           %s\n", ConvertToBinary(-10).c_str());
    printf("float:         %s\n", ConvertToBinary(10.0f).c_str());
    printf("-float:        %s\n", ConvertToBinary(-10.0f).c_str());
    printf("unsigned long: %s\n", ConvertToBinary(long(10)).c_str());
    printf("long:          %s\n", ConvertToBinary(long(-10)).c_str());
    printf("double:        %s\n", ConvertToBinary(10.0).c_str());
    printf("-double:       %s\n", ConvertToBinary(-10.0).c_str());
    
    printf("unsigned:      %s\n", ConvertToOct(10).c_str());
    printf("int:           %s\n", ConvertToOct(-10).c_str());
    printf("float:         %s\n", ConvertToOct(10.0f).c_str());
    printf("-float:        %s\n", ConvertToOct(-10.0f).c_str());
    printf("unsigned long: %s\n", ConvertToOct(long(10)).c_str());
    printf("long:          %s\n", ConvertToOct(long(-10)).c_str());
    printf("double:        %s\n", ConvertToOct(10.0).c_str());
    printf("-double:       %s\n", ConvertToOct(-10.0).c_str());
    
    printf("unsigned:      %s\n", ConvertToHex(10).c_str());
    printf("int:           %s\n", ConvertToHex(-10).c_str());
    printf("float:         %s\n", ConvertToHex(10.0f).c_str());
    printf("-float:        %s\n", ConvertToHex(-10.0f).c_str());
    printf("unsigned long: %s\n", ConvertToHex(long(10)).c_str());
    printf("long:          %s\n", ConvertToHex(long(-10)).c_str());
    printf("double:        %s\n", ConvertToHex(10.0).c_str());
    printf("-double:       %s\n", ConvertToHex(-10.0).c_str());
    
    printf("\n");
    printf(" ############################## End ztest_bitset.cpp.. ############################## \n");
  }
  
}

#ifndef _RUN_ALL_TEST_
int main()
{
  zg::ztest_bitset();
}
#endif
