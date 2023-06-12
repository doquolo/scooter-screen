#include <stdio.h>
#include <time.h>

using namespace std;

struct dateTime{
    int year, month, date, hours, minutes;
};


dateTime getTime(long long int epoch, int offset_sec, long long int elapsed_sec) {
    time_t current_time = epoch + offset_sec + elapsed_sec;
    struct tm* ptime;
    ptime = gmtime(&current_time);
    dateTime data = {int(ptime->tm_year % 100), int(ptime->tm_mon + 1), int(ptime->tm_mday), int(ptime->tm_hour), int(ptime->tm_min)};
    return data;
}