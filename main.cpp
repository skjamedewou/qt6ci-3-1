#include <QCoreApplication>
#include "test.h"

void lifecycle()
{
    Test t;
}

void notifications()
{
    Test mom;
    Test child;
    mom.setObjectName("Mom");
    child.setObjectName("Child");
    //qDebug() << &mom; // to see if mom or child is constructed first
    //qDebug() << &child;

    QObject::connect(&mom, &Test::alarm, &child, &Test::wake, Qt::ConnectionType::AutoConnection);

    mom.testing(); // you can call slot as function with mom.wake(); but you will lose the connection between objects. there is no sender
}

void testPointer(QObject *obj)
{
    qInfo() << obj;
}

void testAdress(QObject &obj)
{
    qInfo() <<&obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    //lifecycle();
    //notifications();

    QObject person;

    testPointer(&person);
    testAdress(person);

    return a.exec();
}
