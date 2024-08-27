#ifndef BLOCKINGMODEL_H
#define BLOCKINGMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QDateTime>

class BlockingModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum BlockingRoles {
        BlockingDateRole = Qt::UserRole + 1,
        BlockingTimeRole,
        IsUnblockedRole,
        BlockingMessageRole
    };

    BlockingModel(QObject *parent = nullptr);

    void loadFromJson(const QString &filePath);
    void saveToJson(const QString &filePath);
    void addBlockingRecord(const QString &blockingMessage, bool isUnblocked = false);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    struct BlockingRecord {
        QString blockingDate;
        QString blockingTime;
        bool isUnblocked;
        QString blockingMessage;
    };

    QList<BlockingRecord> m_records;
};

#endif // BLOCKINGMODEL_H
