#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}

int main()
{
   std::map<std::vector<std::string>, int> bus;
   int bus_number {1};

   auto count = get<int>(std::cin); 
   while (count--) {
      std::vector<std::string> v;
      auto stop_count = get<int>(std::cin);
      while (stop_count--)
         v.push_back (get<std::string>(std::cin));
      if (bus.count(v)) {
         std::cout << "Already exists for " << bus[v] << std::endl;
      } else {
         bus[v] = bus_number;
         std::cout << "New bus " << bus_number++ << std::endl;
      }
   } // while (count--) {
} // int main()