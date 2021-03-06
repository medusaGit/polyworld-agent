#include "polyworldagent.h"
#include <QApplication>
#include <QtWidgets>

#include "NetworkClient.h"
#include "MulticastReceiver.h"
#include "Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PolyworldAgent polyWorldAgent;
    // only show this after we have connected
    polyWorldAgent.show();

    /*
    Client client;
    client.start("127.0.0.1", 8888);
    */

    NetworkClient networkClient;
    networkClient.show();

    // update status from networkclient
    QObject::connect(&networkClient, SIGNAL(setStatus(QString)), &polyWorldAgent, SLOT(appendStatus(QString)));

    // init world from world file after client has downloaded it
    QObject::connect(&networkClient, SIGNAL(startWorldInit()), &polyWorldAgent, SLOT(initFromWorldFile()));

    /*
    MulticastReceiver multicastReceiver;
    // multicastReceiver.show();

    QObject::connect(&multicastReceiver, SIGNAL(setStatus(QString)),
                     &polyWorldAgent, SLOT(appendStatus(QString)));

    QObject::connect(&multicastReceiver, SIGNAL(serverStep(int,int,int,float)),
                     &polyWorldAgent, SLOT(serverStep(int,int,int,float)));

    QObject::connect(&multicastReceiver, SIGNAL(moveAgent(long,float,float,float,float,float,float,float)),
                     &polyWorldAgent, SLOT(drawAgentMove(long,float,float,float,float,float,float,float)));

    QObject::connect(&multicastReceiver, SIGNAL(agentBorn(long,float,float,float)),
                     &polyWorldAgent, SLOT(addAgent(long,float,float,float)));

    QObject::connect(&multicastReceiver, SIGNAL(agentDied(long)),
                     &polyWorldAgent, SLOT(removeAgent(long)));

    QObject::connect(&multicastReceiver, SIGNAL(foodAdded(long,float,float,float,float)),
                     &polyWorldAgent, SLOT(addFood(long,float,float,float,float)));

    QObject::connect(&multicastReceiver, SIGNAL(foodRemoved(long)),
                     &polyWorldAgent, SLOT(removeFood(long)));

    QObject::connect(&multicastReceiver, SIGNAL(foodChanged(long,float,float,float)),
                     &polyWorldAgent, SLOT(changeFood(long,float,float,float)));
    */

    return a.exec();
}
