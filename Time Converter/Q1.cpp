#include <iostream>
using namespace std;

class TimeConverter
{
public:
  
    void secondsToTime(int totalSeconds)
    {
        int hours, minutes, seconds;
        hours = totalSeconds / 3600;
        totalSeconds = totalSeconds % 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
        cout << "Time is: " << hours << ":" << minutes << ":" << seconds << "\n";
    }

    
    int timeToSeconds(int hours, int minutes, int seconds)
    {
        int total = (hours * 3600) + (minutes * 60) + seconds;
        return total;
    }
};

int main()
{
    TimeConverter tc;
    int choice;

    do
    {
        cout << "\n--- Time Converter Menu ---\n";
        cout << "1. Convert seconds to HH:MM:SS\n";
        cout << "2. Convert HH:MM:SS to seconds\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int totalSeconds;
            cout << "Enter total seconds: ";
            cin >> totalSeconds;
            tc.secondsToTime(totalSeconds);
        }
        else if (choice == 2)
        {
            int h, m, s;
            cout << "Enter hours: ";
            cin >> h;
            cout << "Enter minutes: ";
            cin >> m;
            cout << "Enter seconds: ";
            cin >> s;

            int total = tc.timeToSeconds(h, m, s);
            cout << "Total seconds are: " << total << "\n";
        }

    } while (choice != 3);

    cout << "Program ended." << "\n";
    return 0;
}
