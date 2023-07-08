#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <AppManager.h>
#include <QtLogging>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    // exposing C++ object to Qml
    AppManager *appManager = new AppManager(&app);
    engine.rootContext()->setContextProperty("AppManager", appManager);
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());
    const QUrl url(u"qrc:/rose-quick/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
