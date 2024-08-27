#include "alarmhistory.h"
#include <QDebug>

AlarmModel::AlarmModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void AlarmModel::loadFromJson(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for reading:" << filePath;
        qWarning() << "Error:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (!jsonDoc.isObject()) {
        qWarning() << "Invalid JSON format";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    QJsonArray recordsArray = jsonObj["alarm_history"].toArray();

    beginResetModel();
    m_records.clear();
    for (const QJsonValue &value : recordsArray) {  // 使用引用
        QJsonObject obj = value.toObject();
        AlarmRecord record;
        record.alarmDate = obj["alarm_date"].toString();
        record.alarmTime = obj["alarm_time"].toString();
        record.recoverTime = obj["recover_time"].toString();
        record.isFault = obj["is_fault"].toBool();
        record.alarmMessage = obj["alarm_message"].toString();
        m_records.append(record);
    }
    endResetModel();
}

void AlarmModel::saveToJson(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing:" << filePath;
        qWarning() << "Error:" << file.errorString();
        return;
    }

    QJsonArray recordsArray;
    for (const AlarmRecord &record : m_records) {
        QJsonObject obj;
        obj["alarm_date"] = record.alarmDate;
        obj["alarm_time"] = record.alarmTime;
        obj["recover_time"] = record.recoverTime;
        obj["is_fault"] = record.isFault;
        obj["alarm_message"] = record.alarmMessage;
        recordsArray.append(obj);
    }

    QJsonObject jsonObj;
    jsonObj["alarm_history"] = recordsArray;
    QJsonDocument jsonDoc(jsonObj);

    file.write(jsonDoc.toJson());
    file.close();
}

void AlarmModel::addAlarmRecord(const QString &alarmMessage, bool isFault, const QString &recoverTime) {
    AlarmRecord record;
    QDateTime currentDateTime = QDateTime::currentDateTime();
    record.alarmDate = currentDateTime.toString("yyyy-MM-dd");
    record.alarmTime = currentDateTime.toString("hh:mm:ss");
    record.recoverTime = recoverTime;
    record.isFault = isFault;
    record.alarmMessage = alarmMessage;

    beginInsertRows(QModelIndex(), 0, 0);  // 通知视图即将插入新行
    m_records.prepend(record);
    endInsertRows();  // 通知视图插入新行完成
}

int AlarmModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_records.count();
}

QVariant AlarmModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_records.count())
        return QVariant();

    const AlarmRecord &record = m_records.at(index.row());
    switch (role) {
    case AlarmDateRole:
        return record.alarmDate;
    case AlarmTimeRole:
        return record.alarmTime;
    case RecoverTimeRole:
        return record.recoverTime;
    case IsFaultRole:
        return record.isFault;
    case AlarmMessageRole:
        return record.alarmMessage;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> AlarmModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[AlarmDateRole] = "alarm_date";
    roles[AlarmTimeRole] = "alarm_time";
    roles[RecoverTimeRole] = "recover_time";
    roles[IsFaultRole] = "is_fault";
    roles[AlarmMessageRole] = "alarm_message";
    return roles;
}
