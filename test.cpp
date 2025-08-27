#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<"Constructed";
}

Test::~Test()
{
    qInfo()<<this<<"Deconstructed";
}

void Test::testing()
{
    QString noise = "WAKE UP!!!";
    emit alarm(noise);

    // this->wake("Hello"); // it can be done this way
}

void Test::wake(QString noise)
{
    qInfo()<<"From" << sender() <<noise;
}
