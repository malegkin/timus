#include <iostream>
#include <string>

const uint32_t TOTAL_NUMBER_OF_TASKS = 12;
const uint32_t DURATION_OF_WORLD_CUP_MINUTES = 5*60;
const uint32_t TIME_FOR_RESOLVE_LAST_TASK_MINUTES = 45;


std::string assesment(const uint32_t first_hour_tasks)
{
    uint32_t time_for_resolve_all_last_tasks = 
        TIME_FOR_RESOLVE_LAST_TASK_MINUTES * (TOTAL_NUMBER_OF_TASKS - first_hour_tasks);

    if (DURATION_OF_WORLD_CUP_MINUTES - 60 > time_for_resolve_all_last_tasks )
        return "YES";

    return "NO";
}


int main()
{    
    uint32_t first_hour_tasks;
    std::cin >> first_hour_tasks;

    std::cout << assesment(first_hour_tasks) << std::endl;

    return 0;
}