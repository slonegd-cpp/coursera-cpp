/**
 * хотя задание прошло, реализация мне не нравится
 * в решении от курсов изящнее
 *    // если имя неизвестно, возвращает пустую строку
      string FindNameByYear(const map<int, string>& names, int year) {
      string name;  // изначально имя неизвестно
      
      // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
      for (const auto& item : names) {
         // если очередной год не больше данного, обновляем имя
         if (item.first <= year) {
            name = item.second;
         } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
         }
      }
      
      return name;
      }
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

struct Name {
   std::string first;
   std::string last;
};


class Person {
public:
   void ChangeFirstName (int year, const std::string& first_name) {
      if (map.count(year))
         map[year] = {first_name, map[year].last};
      else
         map[year] = {first_name, ""};
   }
   void ChangeLastName (int year, const std::string& last_name) {
      if (map.count(year))
         map[year] = {map[year].first, last_name};
      else
         map[year] = {"", last_name};
   }
   std::string GetFullName (int year) {
      std::string first, last;
      while (year) {
         if (map.count(year)) {
            if (first.empty() and map[year].first.size() ) first = map[year].first;
            if (last.empty()  and map[year].last .size() ) last = map[year].last;
            if (first.size() and last.size()) break;
         }
         year--;
      }
      return first.empty() and last.empty() ? "Incognito" :
             first.size()  and last.empty() ? first + " with unknown last name" :
             first.empty() and last.size()  ? last  + " with unknown first name" :
             first + " " + last;
   }

private:
   std::map<int, Name> map;
};








// int main() {
//    Person person;
   
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//       std::cout << person.GetFullName(year) << std::endl;
//    }
   
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//       std::cout << person.GetFullName(year) << std::endl;
//    }
   
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//       std::cout << person.GetFullName(year) << std::endl;
//    }
   
//    return 0;
// }

/**
 * хотя задание прошло, реализация мне не нравится
 * в решении от курсов изящнее
 *    // если имя неизвестно, возвращает пустую строку
      string FindNameByYear(const map<int, string>& names, int year) {
      string name;  // изначально имя неизвестно
      
      // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
      for (const auto& item : names) {
         // если очередной год не больше данного, обновляем имя
         if (item.first <= year) {
            name = item.second;
         } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
         }
      }
      
      return name;
      }
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

struct Name {
   std::string first;
   std::string last;
};


class Person {
public:
   void ChangeFirstName (int year, const std::string& first_name) {
         first[year] = first_name;
   }
   void ChangeLastName (int year, const std::string& last_name) {
      last[year] = last_name;
   }
   std::string GetFullName (int year) {
      std::string first = get_name(this->first(), year);
      std::string last  = get_name(this->last() , year);

      return first.empty() and last.empty() ? "Incognito" :
             first.size()  and last.empty() ? first + " with unknown last name" :
             first.empty() and last.size()  ? last  + " with unknown first name" :
             first + " " + last;
   }

   // std::string GetFullNameWithHistory(int year) {
   //    // получить все имена и фамилии по состоянию на конец года year
   // }

private:
   std::map<int, std::string> first;
   std::map<int, std::string> last;

   std::string get_name (std::map<int, std::string>& map, int year)
   {
      std::string res;
      for (const auto& p : map) {
         if (p.first > year)
            break;
         else
            res = p.second;
      }
      return res;
   }
};








int main() {
   Person person;
   
   person.ChangeFirstName(1965, "Polina");
   person.ChangeLastName(1967, "Sergeeva");
   for (int year : {1900, 1965, 1990}) {
      std::cout << person.GetFullName(year) << std::endl;
   }
   
   person.ChangeFirstName(1970, "Appolinaria");
   for (int year : {1969, 1970}) {
      std::cout << person.GetFullName(year) << std::endl;
   }
   
   person.ChangeLastName(1968, "Volkova");
   for (int year : {1969, 1970}) {
      std::cout << person.GetFullName(year) << std::endl;
   }
   
   return 0;
}