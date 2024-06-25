#ifndef TEMP_B
#define TEMP_B
//Это - header функций псевдографики

//Подключим библиотеку
#include <locale.h>
#include <stdio.h>
#include "temp_functions.h"



//Опишем заголовки функций

/**
 * @brief Эта функция делает то-то
*/
void banner_help();
void banner_get_starting();
void banner_error_file_path();  
void banner_error_month();
void banner_there_is_no_month();
void banner_error_reading();
void banner_test();
void banner_error_in_string(int num);
void banner_month_statistic(year_statistic *stat, int mon);
void banner_year_statistic(year_statistic *stat);
#endif