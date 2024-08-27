#include "blockingmodel.h"
#include <QDebug>
#include <QDir>

BlockingModel::BlockingModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void BlockingModel::loadFromJson(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << filePath;
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
    QJsonArray recordsArray = jsonObj["blocking_records"].toArray();

    beginResetModel();
    m_records.clear();
    for (const QJsonValue &value : recordsArray) {  // 使用引用
        QJsonObject obj = value.toObject();
        BlockingRecord record;
        record.blockingDate = obj["blocking_date"].toString();
        record.blockingTime = obj["blocking_time"].toString();
        record.isUnblocked = obj["is_unblocked"].toBool();
        record.blockingMessage = obj["blocking_message"].toString();
        m_records.append(record);
    }
    endResetModel();
}

void BlockingModel::saveToJson(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing:" << filePath;
        qWarning() << "Error:" << file.errorString();
        return;
    }

    QJsonArray recordsArray;
    for (const BlockingRecord &record : m_records) {
        QJsonObject obj;
        obj["blocking_date"] = record.blockingDate;
        obj["blocking_time"] = record.blockingTime;
        obj["is_unblocked"] = record.isUnblocked;
        obj["blocking_message"] = record.blockingMessage;
        recordsArray.append(obj);
    }

    QJsonObject jsonObj;
    jsonObj["blocking_records"] = recordsArray;
    QJsonDocument jsonDoc(jsonObj);

    file.write(jsonDoc.toJson());
    file.close();
}

void BlockingModel::addBlockingRecord(const QString &blockingMessage, bool isUnblocked) {
    BlockingRecord record;
    QDateTime currentDateTime = QDateTime::currentDateTime();
    record.blockingDate = currentDateTime.toString("yyyy-MM-dd");
    record.blockingTime = currentDateTime.toString("hh:mm:ss");
    record.isUnblocked = isUnblocked;
    record.blockingMessage = blockingMessage;

    beginInsertRows(QModelIndex(), 0, 0);  // 通知视图即将插入新行
    m_records.prepend(record);
    endInsertRows();  // 通知视图插入新行完成
}

int BlockingModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_records.count();
}

QVariant BlockingModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_records.count())
        return QVariant();

    const BlockingRecord &record = m_records.at(index.row());
    switch (role) {
    case BlockingDateRole:
        return record.blockingDate;
    case BlockingTimeRole:
        return record.blockingTime;
    case IsUnblockedRole:
        return record.isUnblocked;
    case BlockingMessageRole:
        return record.blockingMessage;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> BlockingModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[BlockingDateRole] = "blocking_date";
    roles[BlockingTimeRole] = "blocking_time";
    roles[IsUnblockedRole] = "is_unblocked";
    roles[BlockingMessageRole] = "blocking_message";
    return roles;
}
