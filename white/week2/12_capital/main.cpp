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
   std::map<std::string, std::string> map;

   auto count = get<int>(std::cin); 
   while (count--) {
      auto command = get<std::string>(std::cin);

      if (command == "CHANGE_CAPITAL") {
         auto country = get<std::string>(std::cin);
         auto capital = get<std::string>(std::cin);
         if (map[country] == "") { // не надо сравнивать так, можно вызвать метод count
            std::cout << "Introduce new country " << country << " with capital " << capital << std::endl;
            map.erase (country);
         } else if (map[country] == capital) {
            std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
         } else {
            std::cout << "Country " << country << " has changed its capital from " << map[country] << " to " << capital << std::endl;
         }
         map[country] = capital;
         continue;
      }

      if (command == "RENAME") {
         auto old = get<std::string>(std::cin);
         auto new_ = get<std::string>(std::cin);
         if (new_ == old) {
            std::cout << "Incorrect rename, skip" << std::endl;
         } else if (map[old] == "") {
            std::cout << "Incorrect rename, skip" << std::endl;
            map.erase (old);
         } else if (map[new_] != "") {
            std::cout << "Incorrect rename, skip" << std::endl;
         } else {
            std::cout << "Country " << old << " with capital " << map[old] << " has been renamed to " << new_ << std::endl;
            map[new_] = map[old];
            map.erase (old);
         }
         continue;
      }

      if (command == "ABOUT") {
         auto country = get<std::string>(std::cin);
         if (map[country] == "") {
            std::cout << "Country " << country << " doesn't exist" << std::endl;
            map.erase (country);
         } else {
            std::cout << "Country " << country << " has capital " << map[country] << std::endl;
         }
         continue;
      }

      if (command == "DUMP") {
         if (map.size()) {
            for (const auto& p : map)
               std::cout << p.first << '/' << p.second << ' ';
         } else {
            std::cout << "There are no countries in the world";
         }
         std::cout << std::endl;
         continue;
      }
   } // while (count--) {
} // int main()