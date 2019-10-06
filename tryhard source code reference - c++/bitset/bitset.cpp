

#include "bitset.h"

namespace zg{

    void Print_BuiltInTypeSize()
    {
        printf("bool:               %lu Byte, \n", sizeof(bool));
        printf("char:               %lu Byte, \n", sizeof(char));
        printf("short:              %lu Byte, \n", sizeof(short));
        printf("int:                %lu Byte, \n", sizeof(int));
        printf("long:               %lu Byte, \n", sizeof(long int));
        printf("long long:          %lu Byte, \n", sizeof(long long int));

        printf("unsigned char:      %lu Byte, \n", sizeof(unsigned char));
        printf("unsigned short:     %lu Byte, \n", sizeof(unsigned short));
        printf("unsigned int:       %lu Byte, \n", sizeof(unsigned int));
        printf("unsigned long:      %lu Byte, \n", sizeof(unsigned long int));
        printf("unsigned long long: %lu Byte, \n", sizeof(unsigned long long int));

        printf("float:              %lu Byte, \n", sizeof(float));
        printf("double:             %lu Byte, \n", sizeof(double));
        printf("long double:        %lu Byte, \n", sizeof(long double));
    }

    std::string ConvertToBinary(unsigned number_)
    {
        char tmp[33];
        for(int i = 0; i < 32; ++i)
        {
            tmp[32 - i - 1] = HexChar[ (number_ >> i) & 1 ];
        }
        tmp[32] = '\0';
        return std::string{ tmp };
    }
    std::string ConvertToBinary(int number_)
    {
        return ConvertToBinary(*reinterpret_cast<unsigned *>(&number_));
    }
    std::string ConvertToBinary(float number_)
    {
        return ConvertToBinary(*reinterpret_cast<unsigned *>(&number_));
    }
    std::string ConvertToBinary(unsigned long number_)
    {
        char tmp[65];
        for(int i = 0; i < 64; ++i)
        {
            tmp[64 - i - 1] = HexChar[ (number_ >> i) & 1 ];
        }
        tmp[64] = '\0';
        return std::string{ tmp };
    }
    std::string ConvertToBinary(long number_)
    {
        return ConvertToBinary(*reinterpret_cast<unsigned long *>(&number_));
    }
    std::string ConvertToBinary(double number_)
    {
        return ConvertToBinary(*reinterpret_cast<unsigned long *>(&number_));
    }


    std::string ConvertToOct(unsigned number_)
    {
        char tmp[12];
        for(int i = 0; i < 11; ++i)
        {
            tmp[11 - i - 1] = HexChar[ (number_ >> (i * 3)) & 0x7 ];
        }
        tmp[11] = '\0';
        return std::string{ tmp };
    }
    std::string ConvertToOct(int number_)
    {
        return ConvertToOct(*reinterpret_cast<unsigned *>(&number_));
    }
    std::string ConvertToOct(float number_)
    {
        return ConvertToOct(*reinterpret_cast<unsigned *>(&number_));
    }
    std::string ConvertToOct(unsigned long number_)
    {
        char tmp[23];
        for(int i = 0; i < 22; ++i)
        {
            tmp[22 - i - 1] = HexChar[ (number_ >> (i * 3)) & 0x7 ];
        }
        tmp[22] = '\0';
        return std::string{ tmp };
    }
    std::string ConvertToOct(long number_)
    {
        return ConvertToOct(*reinterpret_cast<unsigned long *>(&number_));
    }
    std::string ConvertToOct(double number_)
    {
        return ConvertToOct(*reinterpret_cast<unsigned long *>(&number_));
    }


    std::string ConvertToHex(unsigned number_)
    {
        char tmp[9];
        for(int i = 0; i < 8; ++i)
        {
            tmp[8 - i - 1] = HexChar[ (number_ >> (i * 4)) & 0xF ];
        }
        tmp[8] = '\0';
        return "0x" + std::string{ tmp };
    }
    std::string ConvertToHex(int number_)
    {
        return ConvertToHex(*reinterpret_cast<unsigned *>(&number_));
    }
    std::string ConvertToHex(float number_)
    {
        return ConvertToHex(*reinterpret_cast<unsigned *>(&number_));
    }
        std::string ConvertToHex(unsigned long number_)
    {
        char tmp[17];
        for(int i = 0; i < 16; ++i)
        {
            tmp[16 - i - 1] = HexChar[ (number_ >> (i * 4)) & 0xF ];
        }
        tmp[16] = '\0';
        return "0x" + std::string{ tmp };
    }
    std::string ConvertToHex(long number_)
    {
        return ConvertToHex(*reinterpret_cast<unsigned long *>(&number_));
    }
    std::string ConvertToHex(double number_)
    {
        return ConvertToHex(*reinterpret_cast<unsigned long *>(&number_));
    }

} //namespace zg
