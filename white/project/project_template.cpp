#include <string>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <iterator>

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}


class Date {
   int year;
   int month;
   int day;
public:
   Date() = default;
   Date (int year, int month, int day) : year{year}, month{month}, day{day} {}
   int GetYear()  const { return year;  }
   int GetMonth() const { return month; }
   int GetDay()   const { return day;   }
   int time() const { return day + month*31 + year*31*12; }
};

bool operator< (const Date& l, const Date& r) { return l.time() < r.time(); }

std::ostream& operator<< (std::ostream& s, const Date& d)
{
   return s << std::setfill('0') << std::setw(4) << d.GetYear()
                          << '-' << std::setw(2) << d.GetMonth() 
                          << '-' << std::setw(2) << d.GetDay();
}

std::istream& operator>> (std::istream& s, Date& d)
{
   auto str = get<std::string>(s);
   std::stringstream ss (str);
   auto year = get<int>(ss);
   if (ss.peek() != '-') throw std::invalid_argument ("Wrong date format: " + str);
   ss.ignore(1);
   auto month = get<int>(ss);
   if (ss.peek() != '-') throw std::invalid_argument ("Wrong date format: " + str);
   ss.ignore(1);
   auto day = get<int>(ss);
   if (not ss.eof()) throw std::invalid_argument ("Wrong date format: " + str);
   if (month < 1 or month > 12)
      throw std::invalid_argument ("Month value is invalid: " + std::to_string(month));
   if (day < 1 or day > 31)
      throw std::invalid_argument ("Day value is invalid: " + std::to_string(day));
   d = Date {year, month, day};
   return s;
}

class Database {
   std::map<Date, std::set<std::string>> db;
public:
   void AddEvent (const Date& date, const std::string& event)   { db[date].insert (event); }
   bool DeleteEvent(const Date& date, const std::string& event) { db[date].erase  (event); }
   int  DeleteDate(const Date& date)                            { db.erase (date); }

   std::set<std::string> Find(const Date& date) const
   {
      if (db.count(date))
         return db.at(date);
      else
         return std::set<std::string> {};
   }
   
   void Print() const
   {
      for (const auto& p : db)
         for (const auto& event : p.second)
            std::cout << p.first << ' ' << event << std::endl;
   }
};

int main() {
   
   try {
      Database db;
      std::string command;
      while (std::getline(std::cin, command)) {
         std::stringstream stream (command);
         auto action = get<std::string>(stream);
         if (action == "Add") {
            Date date;
            stream >> date;
            auto event = get<std::string>(stream);
            db.AddEvent (date, event);
            continue;
         }

         if (action == "Del") {
            Date date;
            stream >> date;
            auto event = get<std::string>(stream);
            if (event == "") {
               auto n = db.Find(date).size();
               db.DeleteDate (date);
               std::cout << "Deleted " << n << " events" << std::endl;
            } else {
               if (db.Find(date).count(event)) {
                  db.DeleteEvent (date, event);
                  std::cout << "Deleted successfully" << std::endl;
               } else {
                   std::cout << "Event not found" << std::endl;
               }
            }
            continue;
         }

         if (action == "Find") {
            Date date;
            stream >> date;
            for (const auto& event : db.Find(date))
               std::cout << event << std::endl;
            continue;
         }

         if (action == "Print") {
            db.Print();
            continue;
         }

         if (action != "")
            std::cout << "Unknown command: " << action << std::endl;
      }

   } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
   }


   return 0;
}


