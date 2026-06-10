#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int hour, minute;
    
    while (cin >> hour >> minute) {
        if (hour == -1) break;
        
        hour = hour % 12;
        
        double minuteAngle = minute * 6.0;
        
        double hourAngle = hour * 30.0 + minute * 0.5;
        
        double angle = abs(hourAngle - minuteAngle);
        
        if (angle > 180) {
            angle = 360 - angle;
        }
        
        int result = round(angle);
        
        cout << result << endl;
    }
    
    return 0;
}
