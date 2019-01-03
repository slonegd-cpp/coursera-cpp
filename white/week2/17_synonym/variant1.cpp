// не прошло по времени
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
		

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}

int main()
{
   std::set<std::set<std::string>> synonym;

   auto count = get<int>(std::cin); 
   while (count--) {
      auto command = get<std::string>(std::cin); 

      if (command == "ADD") {
         auto w1 = get<std::string>(std::cin); 
         auto w2 = get<std::string>(std::cin); 
         std::set<std::string> pair {w1, w2};
         synonym.insert (pair);
         continue;
      }

      if (command == "COUNT") {
         auto w = get<std::string>(std::cin);
         auto res = std::count_if (synonym.begin(), synonym.end(),
            [&](const auto& set) {
               return set.count (w);
            }
         );
         std::cout << res << std::endl;
         continue;
      }

      if (command == "CHECK") {
         auto w1 = get<std::string>(std::cin); 
         auto w2 = get<std::string>(std::cin); 
         std::set<std::string> pair {w1, w2};
         if (synonym.count(pair)) {
            std::cout << "YES" << std::endl;
         } else {
            std::cout << "NO" << std::endl;
         }
         continue;
      }
   } // while (count--) {

}