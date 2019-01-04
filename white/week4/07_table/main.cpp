#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}

int main()
{
   std::ifstream file ("input.txt");
   auto lines  = get<int>(file);
   auto colums = get<int>(file);
   while (lines--) {
      auto n = colums;
      while (n--) {
         std::cout << std::setw(10) << get<int>(file);
         if (n != 0) {
            std::cout << ' ';
            file.ignore(1);
         }
      }
      std::cout << std::endl;
   }
}
