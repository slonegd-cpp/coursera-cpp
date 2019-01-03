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

std::ostream& operator<< (std::ostream& s, const std::vector<std::string>& v)
{
   for (const auto& str : v)
      s << str << ' ';
   return s;
}

int main()
{
   std::map<std::string, std::vector<std::string>> bus;
   std::map<std::string, std::vector<std::string>> stop;

   auto count = get<int>(std::cin); 
   while (count--) {
      auto command = get<std::string>(std::cin);

      if (command == "NEW_BUS") {
         auto bus_ = get<std::string>(std::cin);
         auto stop_count = get<int>(std::cin); 
         while (stop_count--) {
            auto stop_ = get<std::string>(std::cin);
            bus[bus_]  .push_back (stop_);
            stop[stop_].push_back (bus_);
         }
         continue;
      }

      if (command == "BUSES_FOR_STOP") {
         auto stop_ = get<std::string>(std::cin);
         if (stop.count(stop_)) {
            std::cout << stop[stop_] << std::endl;
         } else {
            std::cout << "No stop" << std::endl;
         }
         continue;
      }

      if (command == "STOPS_FOR_BUS") {
         auto bus_ = get<std::string>(std::cin);
         if (bus.count(bus_)) {
            for (const auto& stop_ : bus[bus_]) {
               std::cout << "Stop " << stop_ << ':';
               if (stop[stop_].size() == 1) {
                  std::cout << " no interchange";
               } else {
               for (const auto& b : stop[stop_])
                  if (b != bus_)
                   std::cout << ' ' << b;
               }
               std::cout << std::endl;
            }
         } else {
            std::cout << "No bus" << std::endl;
         }
      }

      if (command == "ALL_BUSES") {
         if (bus.size())
            for (const auto& b : bus)
               std::cout << "Bus " << b.first << ": " << b.second << std::endl;
         else
            std::cout << "No buses" << std::endl;
      }
   } // while (count--) {
} // int main()