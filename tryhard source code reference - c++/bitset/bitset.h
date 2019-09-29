#ifndef _ZG_BITSET_H_
#define _ZG_BITSET_H_

#include <stdio.h>
#include <string>

namespace zg
{
    static void Print_BuiltInTypeSize()
    {
        printf("bool:                   %lu \n", sizeof(bool));
        printf("char:                   %lu \n", sizeof(char));
        printf("short:                  %lu \n", sizeof(short));
        printf("int:                    %lu \n", sizeof(int));
        printf("long int:               %lu \n", sizeof(long int));
        printf("long long int:          %lu \n", sizeof(long long int));

        printf("unsigned char:          %lu \n", sizeof(unsigned char));
        printf("unsigned short:         %lu \n", sizeof(unsigned short));
        printf("unsigned int:           %lu \n", sizeof(unsigned int));
        printf("unsigned long int:      %lu \n", sizeof(unsigned long int));
        printf("unsigned long long int: %lu \n", sizeof(unsigned long long int));

        printf("float:                  %lu \n", sizeof(float));
        printf("double:                 %lu \n", sizeof(double));
        printf("long double:            %lu \n", sizeof(long double));
    }

    static const char HexChar[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

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
        return ConvertToBinary(*reinterpret_cast<unsigned*>(&number_));
    }
    std::string ConvertToBinary(float number_)
    {
        return ConvertToBinary(*reinterpret_cast<unsigned*>(&number_));
    }

    std::string ConvertToHex(unsigned number_)
    {
        char tmp[9];
        for(int i = 0; i < 8; ++i)
        {
            tmp[7 - i] = HexChar[ (number_ >> (i * 4)) & 0xF ];
        }
        tmp[8] = '\0';
        return "0x" + std::string{ tmp };
    }
    std::string ConvertToHex(int number_)
    {
        return ConvertToHex(*reinterpret_cast<unsigned*>(&number_));
    }
    std::string ConvertToHex(float number_)
    {
        return ConvertToHex(*reinterpret_cast<unsigned*>(&number_));
    }

}

#endif //_ZG_BITSET_H_
