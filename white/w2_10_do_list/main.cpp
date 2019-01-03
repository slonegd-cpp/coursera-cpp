#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iterator>

using Do_list = std::vector<std::string>;

std::ostream& operator& (std::iostream& s, const Do_list& list)
{
   s << list.size() << ' ';
   for (auto& str : list)
      s << str << ' ';
   s << std::endl;
}

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}



int main()
{
   constexpr std::array days { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   auto action_count = get<int>(std::cin);
   while (action_count--) {

   } // while (action_count--) {
}