#include <string>
#include <array>

// 绝了真的
std::string intToRoman(int num)
{
    std::array<int, 13> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::array<std::string, 13> reps = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string res;
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            num -= values[i];
            res += reps[i];
        }
    }
    return res;
}