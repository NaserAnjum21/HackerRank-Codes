#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<> struct Traits<Fruit>
{
    static string name(int id)
    {
        if(id == 0) return "apple";
        if(id == 1) return "orange";
        if(id == 2) return "pear";
        return "unknown";
    }
};

template<> struct Traits<Color>
{
    static string name(int id)
    {
        if(id == 0) return "red";
        if(id == 1) return "green";
        if(id == 2) return "orange";
        return "unknown";
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
