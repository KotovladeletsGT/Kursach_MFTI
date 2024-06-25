

#include "banner_functions.h"
#include "temp_functions.h"

void banner_get_starting() {
    wprintf(L" ╔════════════════════════════════════╗ \n");
    wprintf(L" ║  Для получения справки введите -h  ║ \n");
    wprintf(L" ╚════════════════════════════════════╝ \n");
}

void banner_help() {
    wprintf(L" ╔═════════════════════════════════════════════════════════════════════════╗ \n");
    wprintf(L" ║                                 СПРАВКА                                 ║ \n");
    wprintf(L" ╠═════════════════════════════════════════════════════════════════════════╣ \n");
    wprintf(L" ║  Программа предназначена для обработки информации с датчика температуры ║ \n");
    wprintf(L" ║  Доступен вывод следующих данных за месяц:                              ║ \n");
    wprintf(L" ║      1. Среднемесячная температура                                      ║ \n");
    wprintf(L" ║      2. Минимальная температура в текущем месяце                        ║ \n");
    wprintf(L" ║      3. Максимальная температура в текущем месяце                       ║ \n");
    wprintf(L" ║  Так же возможен вывод статистики за год:                               ║ \n");
    wprintf(L" ║      1. Среднегодовая температура                                       ║ \n");
    wprintf(L" ║      2. Минимальная температура                                         ║ \n");
    wprintf(L" ║      3. Максимальная температура                                        ║ \n");                               
    wprintf(L" ╠═════════════════════════════════════════════════════════════════════════╣ \n");
    wprintf(L" ║  Для использования программы введите:                                   ║ \n");
    wprintf(L" ║      1. -h для получения справки                                        ║ \n");
    wprintf(L" ║      2. -f <имя_вашего_файла.csv> для подключения файла с данными       ║ \n");
    wprintf(L" ║      3. -m <номер месяца> если вы хотите получить статистику за месяц   ║ \n");                               
    wprintf(L" ╚═════════════════════════════════════════════════════════════════════════╝ \n");
}

void banner_error_file_path() {
    wprintf(L" ╔════════════════════════════╗ \n");
    wprintf(L" ║  Путь к файлу не указан!   ║ \n");
    wprintf(L" ╚════════════════════════════╝ \n");
}

void banner_there_is_no_month() {
    wprintf(L" ╔════════════════════════════╗ \n");
    wprintf(L" ║      Месяц не указан!      ║ \n");
    wprintf(L" ╚════════════════════════════╝ \n");
}

void banner_error_month() {
    wprintf(L" ╔════════════════════════════╗ \n");
    wprintf(L" ║    Месяц указан неверно!   ║ \n");
    wprintf(L" ╚════════════════════════════╝ \n");
}

void banner_error_reading() {
    wprintf(L" ╔════════════════════════════╗ \n");
    wprintf(L" ║    Ошибка чтения файла!    ║ \n");
    wprintf(L" ╚════════════════════════════╝ \n");
}

void banner_test(){
    wprintf(L"Тест\n");
}

void banner_error_in_string(int num) {
    wprintf(L" ╔════════════════════════════╗ \n");
    wprintf(L" ║    Ошибка в строке № %d     \n", num);
    wprintf(L" ╚════════════════════════════╝ \n");
}

void banner_month_statistic(year_statistic *stat, int mon) {
    char p[20] = {0};
    number_to_month(mon, p);
    wprintf(L" ╔═════════════════════════════════════════════════════════════════════════╗ \n");
    wprintf(L" ║         В месяце  %s термометр зафисировал:                           \t \n", &p);
    wprintf(L" ║         1. Среднемесячную температуру  %0.3f                          \t \n", stat->avg_temp);
    wprintf(L" ║         2. Максимальную температуру    %d                             \t \n", stat->max_temp);
    wprintf(L" ║         3. Минимальную температуру     %d                             \t\n", stat->min_temp);                        
    wprintf(L" ╚═════════════════════════════════════════════════════════════════════════╝ \n");
}

void banner_year_statistic(year_statistic *stat){
    wprintf(L" ╔═════════════════════════════════════════════════════════════════════════╗ \n");
    wprintf(L" ║        За текущий календарный год температура составила:                 \n");
    wprintf(L" ║         1. В среднем              %0.3f                               \t \n", stat->avg_temp);
    wprintf(L" ║         2. Максимуально достигла  %d                                  \t \n", stat->max_temp);
    wprintf(L" ║         3. Минимум был            %d                                  \t \n", stat->min_temp);                               
    wprintf(L" ╠═════════════════════════════════════════════════════════════════════════╣ \n");
    wprintf(L" ║       Ниже представлена собранная статистика за каждый месяц             \n");                             
    wprintf(L" ╚═════════════════════════════════════════════════════════════════════════╝ \n");
    wprintf(L"  \n");
}