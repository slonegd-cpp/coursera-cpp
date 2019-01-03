#include <set>
#include <map>
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
   std::map<std::string,std::set<std::string>> synonym;

   auto count = get<int>(std::cin); 
   while (count--) {
      auto command = get<std::string>(std::cin); 

      if (command == "ADD") {
         auto w1 = get<std::string>(std::cin); 
         auto w2 = get<std::string>(std::cin);
         synonym[w1].insert(w2);
         synonym[w2].insert(w1);
         continue;
      }

      if (command == "COUNT") {
         auto w = get<std::string>(std::cin);
         if (synonym.count(w))
            std::cout << synonym[w].size() << std::endl;
         else
            std::cout << '0' << std::endl;
         continue;
      }

      if (command == "CHECK") {
         auto w1 = get<std::string>(std::cin); 
         auto w2 = get<std::string>(std::cin);
         if (synonym.count(w2))
            if (synonym[w1].count(w2)) {
               std::cout << "YES" << std::endl;
               continue;
            }
         std::cout << "NO" << std::endl;
         continue;
      }
   } // while (count--) {

}