#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class Notification
{
public:
    static void show(const std::string& title, const std::string& message);
    static void hide();
private:
    Notification() { }
};

#endif // NOTIFICATION_H
