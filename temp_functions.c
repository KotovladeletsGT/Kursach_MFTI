//Функции обработки данных с датчика
//Формат данных: (dddd;mm;dd;hh;mm;temperature)

#include "temp_functions.h"
#include "banner_functions.h"

int get_month(char* str) {
    int num = 0;
    while(*str) {
        num = num*10 + (*str++ - '0');
    }
    return num;
}

//Раставляем флаги
void get_flags(flags *flag, int argc, char *argv[]) { 
    if (argc > 1) {
        for(int i = 1; i < argc; i++) {
            if (strcmp(argv[i], FILE_PATH) == 0) {
                flag->file_flag = 1;
                if (argc - i < 2) {
                    //В зависимости от кол-ва аргументов решаем, указан ли путь к  файлу
                    //Печатаем сообщение если он не указан, выставляем флаг ошибки
                    banner_error_file_path();
                    flag->error = 1;
                } else {
                    //Если путь указан - запоминаем
                    flag->file_path = argv[i + 1];
                }
            }
            if (strcmp(argv[i], MONTH) == 0) {
                flag->month_flag = 1;
                if (argc - 1 - i < 1) {
                    //Если месяц не указан
                    banner_there_is_no_month();
                    flag->error = 1;
                } else {
                    //Если месяц указан - запоминаем
                    int month = 0;
                    month = get_month(argv[i + 1]);
                    if(0 < month && month < 13 ) {
                        flag->month = month;
                    } else {
                        //Если месяц указан неверно - пишем ошибку, выставляем флаг ошибки
                        banner_error_month();
                        flag->error= 1;
                    }
                }
            }
            if (strcmp(argv[i], HELP) == 0) {
                flag->help_flag = 1;
            }
        }

    }
}

void number_to_month (int num, char* month) {
    const char *ptr[] = {"NONE" , "January" , "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    strcpy(month, ptr[num]);
}

void push(stack **p, data_from_sensor data) {
    stack* ptmp;
    ptmp = malloc(sizeof(stack));
    ptmp->value.year = data.year;
    ptmp->value.month = data.month;
    ptmp->value.day = data.day;
    ptmp->value.hour = data.hour;
    ptmp->value.minute = data.minute;
    ptmp->value.temperature = data.temperature;
    ptmp->next = *p;
    *p = ptmp;
}

_Bool empty_stack(stack *p) {
    return p == NULL;
}

void get_statistic(stack **p, year_statistic *statistic) {

    static int sum[12] = {0};
    static int iter[12] = {0};
    static int minimal[12] = { 999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 999};
    static int maximum[12] = {-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999};
    static int tmp;
    for(stack *ptmp = *p; ptmp != NULL; ptmp = ptmp->next) {
        tmp = ptmp->value.month - 1;
        sum[tmp] = sum[tmp] + ptmp->value.temperature;
        iter[tmp]++;
        if (maximum[tmp] < ptmp->value.temperature) {
            maximum[tmp] = ptmp->value.temperature;
        }
        if (minimal[tmp] > ptmp->value.temperature) {
            minimal[tmp] = ptmp->value.temperature;
        }
    }
    static int all_sum = 0;
    static int all_iter = 0;
    static int year_min;
    static int year_max; 
    for(int i = 0; i < 12; i++) {
        all_sum += sum[i];
        all_iter += iter[i];
    }
    year_min = minimal[0];
    year_max = maximum[0];
    for(int i = 1; i < 12; i++) {
        if( year_max < maximum [i] ){
            year_max = maximum[i];
        }
        if(year_min > minimal[i] ){
            year_min = minimal[i];
        }
    }
    statistic->avg_temp = 1.0 * all_sum / all_iter;
    statistic->max_temp = year_max;
    statistic->min_temp = year_min;
    for(int i = 0; i < 12; i++) {
        statistic->month[i].avg_temp = 1.0 * sum[i] / iter[i];
        statistic->month[i].max_temp = maximum[i];
        statistic->month[i].min_temp = minimal[i];
    }
}

void file_reader(stack **p, FILE *file) {
    data_from_sensor data = {0};
    int lines_counter = 0;
    char line[256] = {0};
    int tmp;
    while (1) {
        if(fgets(line, sizeof(line), file) == NULL) {
            //Строки в файле закончились
            break;
        }
        tmp = sscanf(line, "%d;%d;%d;%d;%d;%d", &data.year, &data.month, &data.day, &data.hour, &data.minute, &data.temperature);
        if (tmp == 6) {
            push(p, data);
        } else {
            //В строке lines_counter ошибка
            banner_error_in_string(lines_counter + 1);
        }
        lines_counter++;
    }
}
