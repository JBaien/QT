#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSharedMemory>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void loadFromFile();
    void loadFromMemory();

private slots:
    void on_loadFromFileButton_clicked();

    void on_loadFromSharedMemoryButton_clicked();

private:
    Ui::Dialog *ui;
    void detach();
    QSharedMemory sharedMemory;
};

#endif // DIALOG_H
