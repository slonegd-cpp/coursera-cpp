#include <string>
#include <tuple>
#include <map>
#include <iostream>
#include "inc.h"

using namespace std;




TaskStatus operator++(TaskStatus& v)
{
   if (v != TaskStatus::DONE) {
      auto tmp = static_cast<int>(v);
      tmp++;
      v = static_cast<TaskStatus>(tmp);
   }
   return v;
}


class TeamTasks {
   map<string, TasksInfo> task;
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const
  {
     return task.at(person);
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person)
  {
     task[person][TaskStatus::NEW]++;
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
  {
      auto& tp = task[person];
      TasksInfo update, not_update;

      auto i = TaskStatus::NEW;
      for (; i < TaskStatus::DONE; ++i) {
         if (tp.count(i)) {
            if (task_count == 0) {
               not_update[i] = tp[i];
            } else if (tp[i] > task_count) {
               auto tmp = i;
               ++tmp;
               update[tmp] = task_count;
               not_update[i] = tp[i] - task_count;
               task_count = 0;
            } else {
               auto tmp = i;
               ++tmp;
               update[tmp] = tp[i];
               task_count -= tp[i];
            }
         }
      }

      if (tp.count(i)) {
         if (task_count < tp[i])
            not_update[i] = tp[i] - task_count;
      }

      // for (auto it = update.begin(); it != update.end(); ++it)
      //    if (it->second == 0)
      //       it = update.erase(it);

      // for (auto it = not_update.begin(); it != not_update.end(); ++it)
      //    if (it->second == 0)
      //       it = not_update.erase(it);

      tp.clear();
      for (auto& p : update)
         tp[p.first] = p.second;
      for (auto& p : not_update)
         tp[p.first] += p.second;

      return {update, not_update};
  }
};






void Print (const TasksInfo& tasks_info)
{
   if (tasks_info.empty()) {
      cout << 0 << endl;
      return;
   }
   for (auto& p : tasks_info) {
      switch (p.first) {
         case (TaskStatus::NEW)        : cout << "NEW:"; break;
         case (TaskStatus::IN_PROGRESS): cout << "PROG:"; break;
         case (TaskStatus::TESTING)    : cout << "TEST:"; break;
         case (TaskStatus::DONE)       : cout << "DONE:"; break;
      }
      cout << p.second << ' ';
   }
   cout << endl;
}


int main() {
   TeamTasks tasks;
   auto count {5};
   while (count--) tasks.AddNewTask("Ilia");

   Print(tasks.GetPersonTasksInfo("Ilia")); cout << endl;
   {
      cout << -5 << endl;
      auto [u, n] = tasks.PerformPersonTasks("Ilia", 5);
      Print(u);
      Print(n);
      cout << endl;
   }
   Print(tasks.GetPersonTasksInfo("Ilia")); cout << endl;
   {
      cout << -5 << endl;
      auto [u, n] = tasks.PerformPersonTasks("Ilia", 5);
      Print(u);
      Print(n);
      cout << endl;
   }
   Print(tasks.GetPersonTasksInfo("Ilia"));cout << endl;
   {
      cout << -1 << endl;
      auto [u, n] = tasks.PerformPersonTasks("Ilia", 1);
      Print(u);
      Print(n);
      cout << endl;
   }
   Print(tasks.GetPersonTasksInfo("Ilia"));cout << endl;


   count = 5;
   while (count--) tasks.AddNewTask("Ilia");
   cout << 5 << endl;
   Print(tasks.GetPersonTasksInfo("Ilia"));cout << endl;

   {
      cout << -2 << endl;
      auto [u, n] = tasks.PerformPersonTasks("Ilia", 2);
      Print(u);
      Print(n);
      cout << endl;
   }
   Print(tasks.GetPersonTasksInfo("Ilia"));cout << endl;

   {
      cout << -4 << endl;
      auto [u, n] = tasks.PerformPersonTasks("Ilia", 4);
      Print(u);
      Print(n);
      cout << endl;
   }
   Print(tasks.GetPersonTasksInfo("Ilia"));cout << endl;

  
}