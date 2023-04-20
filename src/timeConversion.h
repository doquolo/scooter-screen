struct dateTime{
    int year, month, date, hours, minutes;
};

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

dateTime convertToLocalTime(int year, int month, int date, int hours, int minutes, int UTCoffset) {
    // adding offest
    hours = hours + UTCoffset;
    // checking whether it's the next day in that offset
    if (hours >= 24) {
        hours = hours - 24;
        // cheack whether its the end of month
        if (date >= 28) {
            // check whether month has 31 or 30 day (or Feb)
            if (month == 2) {
                // cout << "Feb" << endl;
                // check leap year
                if (isLeap(year)) {
                    // cout << "Leap" << endl;
                    if (date < 29) date++;
                    else {
                        date = 1;
                        month++;
                    }
                } else {
                    // cout << "not leap" << endl;
                    if (date < 28) date++;
                    else {
                        date = 1;
                        month++;
                    }
                }

            } else {
                // check whether the month has 30 or 31 day
                if (month % 2 == 0) {
                    // cout << "30 days" << endl;
                    if (date < 30) date++;
                    else {
                        date = 1;
                        month++;
                    }
                } else {
                    // cout << "31 days" << endl;
                    if (date < 31) date++;
                    else {
                        date = 1;
                        month++;
                    }
                }
            }
        }
        else {
            // cout << "not end of month" << endl;
            date++;
        }
    }
    // check whether the next year or not
    if (month > 12) {
        // cout << "next year" << endl;
        month = 1;
        year++;
    }
    dateTime data = {year, month, date, hours, minutes};
    return data;
}