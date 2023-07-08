#ifndef STORYDIALOG_H
#define STORYDIALOG_H

#include <QString>
#include <map>
#include <vector>

class StoryDialogC {
public:
    std::map<int, QList<QList<QString>>>
            Dialogs = std::map<int, QList<QList<QString>>>();

    QList<QString> AddDia(QString typ, QString pic, QString person, QString adds);

    StoryDialogC();
};

#endif // STORYDIALOG_H
