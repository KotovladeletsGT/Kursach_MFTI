#include "temp_functions.h"
#include "banner_functions.h"



//После получения флагов решаем что делать:
//Если одновременно есть ошибка и пользователь ничего не ввёл - выводим справку
int main(int argc, char** argv) {

    flags flag = {
        .file_path = NULL,
        .file_flag = 0,
        .help_flag = 0,
        .month = 0,
        .month_flag = 0,
        .error = 0
    };

    setlocale(LC_ALL, "Rus");

    get_flags(&flag, argc, argv);


    if(flag.error) {
        return 0;
    }

    if((flag.file_flag || flag.help_flag || flag.month_flag) == 0) {
        banner_get_starting();
        return 0;
    }

    if (flag.help_flag) {
        banner_help();
        return 0;
    }

    if (flag.file_flag) {
        FILE *my_file = fopen(flag.file_path, "r");
        stack *all_data = NULL;
        year_statistic statistic = {0};
        if (my_file == NULL){
            banner_error_reading();
            fclose(my_file);
            return 0;
        } else {
            file_reader(&all_data, my_file);
            get_statistic(&all_data, &statistic);
        }

        if (flag.month_flag) {
            banner_month_statistic(&statistic, flag.month);
        } else {
            banner_year_statistic(&statistic);
            int i = 0;
            while(i < 12) {
                banner_month_statistic(&statistic, i + 1);
                i++;
            }
        }
    }        


    return 0;
}

