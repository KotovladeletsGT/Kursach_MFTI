#ifndef TEMP_H
#define TEMP_H

//Подключим библиотеки

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Дефайны для команд

#define HELP "-h"
#define FILE_PATH "-f"
#define MONTH "-m"

//Создадим структуры

//Тут хранятся флаги

typedef struct flags {
    char* file_path;    //Путь до файла
    int file_flag;      //Файл указан?
    int month;          //Номер месяца
    int month_flag;     //Нужно вывести статистику за месяц?
    int help_flag;      //Нужно вывести справку?
    int error;          //Ошибка
} flags;

//Тут хранятся данные для каждого измерения

typedef struct data_from_sensor
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} data_from_sensor;

//Тут хранятся данные за месяц

typedef struct month_statistic
{
    int year;
    int month;
    float avg_temp;
    int min_temp;
    int max_temp;
} month_statistic;

//Тут хранится статистика за год

typedef struct year_statistic
{
    float avg_temp;
    int min_temp;
    int max_temp;
    month_statistic month[12];
} year_statistic;

//Тут хранится информация с датчика

typedef struct list {
    data_from_sensor value;
    struct list *next;
} stack;

//Функции

void get_flags (flags *flag, int argc, char *argv[]);
void number_to_month (int num, char* month);
void push(stack **p, data_from_sensor data);
_Bool empty_stack(stack *p);
void get_statistic(stack **p, year_statistic *statistic);
void file_reader(stack **p, FILE *file);
// void test_print(stack **p);
#endif