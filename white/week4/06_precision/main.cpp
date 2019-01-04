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
   std::cout << std::fixed;
   while (not file.eof())
      std::cout << std::setprecision(3) << get<double>(file) << std::endl;
}
