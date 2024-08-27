#ifndef ALARMMODEL_H
#define ALARMMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QDateTime>

class AlarmModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum AlarmRoles {
        AlarmDateRole = Qt::UserRole + 1,
        AlarmTimeRole,
        RecoverTimeRole,
        IsFaultRole,
        AlarmMessageRole
    };

    AlarmModel(QObject *parent = nullptr);

    void loadFromJson(const QString &filePath);
    void saveToJson(const QString &filePath);
    void addAlarmRecord(const QString &alarmMessage, bool isFault = false, const QString &recoverTime = "");

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    struct AlarmRecord {
        QString alarmDate;
        QString alarmTime;
        QString recoverTime;
        bool isFault;
        QString alarmMessage;
    };

    QList<AlarmRecord> m_records;
};

#endif // ALARMMODEL_H
