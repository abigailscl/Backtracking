#if !defined(__Convert_h)
#define __Convert_h

#include <string>

using namespace std;

template <class T>	class Convert
{
};
template <>			class Convert<int>
{
public:
    int charToInt(char val)
    {
        if (val == 48)
            return 0;
        if (val == 49)
            return 1;
        if (val == 50)
            return 2;
        if (val == 51)
            return 3;
        if (val == 52)
            return 4;
        if (val == 53)
            return 5;
        if (val == 54)
            return 6;
        if (val == 55)
            return 7;
        if (val == 56)
            return 8;
        if (val == 57)
            return 9;

    }
    char intToChar(int val)
    {
        if (val == 0)
            return '0';
        if (val == 1)
            return '1';
        if (val == 2)
            return '2';
        if (val == 3)
            return '3';
        if (val == 4)
            return '4';
        if (val == 5)
            return '5';
        if (val == 6)
            return '6';
        if (val == 7)
            return '7';
        if (val == 8)
            return '8';
        if (val == 9)
            return '9';
    }
};
template <>			class Convert<string>
{
public:
    string lower(string s)
    {
        for (size_t i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);

        return s;
    }
    string charToString(char character)
    {
        if (character == 65)
            return "A";
        if (character == 66)
            return "B";
        if (character == 67)
            return "C";
        if (character == 68)
            return "D";
        if (character == 69)
            return "E";
        if (character == 70)
            return "F";
        if (character == 71)
            return "G";
        if (character == 72)
            return "H";
        if (character == 73)
            return "I";
        if (character == 74)
            return "J";
        if (character == 75)
            return "K";
        if (character == 76)
            return "L";
        if (character == 77)
            return "M";
        if (character == 78)
            return "N";
        if (character == 79)
            return "O";
        if (character == 80)
            return "P";
        if (character == 81)
            return "Q";
        if (character == 82)
            return "R";
        if (character == 83)
            return "S";
        if (character == 84)
            return "T";
        if (character == 85)
            return "U";
        if (character == 86)
            return "V";
        if (character == 87)
            return "W";
        if (character == 88)
            return "X";
        if (character == 89)
            return "Y";
        if (character == 90)
            return "Z";

    }
};
#endif
