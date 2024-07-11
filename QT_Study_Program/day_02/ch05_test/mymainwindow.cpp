#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);

    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
//    ui->menuBar->addSeparator();
    QAction *action_Open = editMenu->addAction(QIcon(":/images/images/open.png"), tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));               // 设置快捷键
    ui->mainToolBar->addAction(action_Open);                        // 工具栏添加动作

    QMenu *editMenu_1 = ui->menuBar->addMenu(tr("布局(&B)"));
    QActionGroup *group = new QActionGroup(this);
    QAction *action_L = group->addAction(tr("左对齐(&L"));
    action_L->setCheckable(true);
    action_L->setShortcut(QKeySequence("Ctrl+L"));
    QAction *action_R = group->addAction(tr("右对齐(&R"));
    action_R->setCheckable(true);
    action_R->setShortcut(QKeySequence("Ctrl+R"));
    QAction *action_C = group->addAction(tr("居中(&C"));
    action_C->setCheckable(true);
    action_C->setShortcut(QKeySequence("Ctrl+C"));
    action_L->setChecked(true);
    editMenu_1->addAction(action_L);
    editMenu_1->addSeparator();
    editMenu_1->addAction(action_R);
    editMenu_1->addSeparator();
    editMenu_1->addAction(action_C);
//    ui->mainToolBar->addAction(action_L);

    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    QMenu *colorMenu = new QMenu(this);             //创建菜单
    QAction *action_Color_red;
    action_Color_red = colorMenu->addAction(tr("红色"));
    action_Color_red->setCheckable(true);
    action_Color_red->setChecked(true);
    colorMenu->addSeparator();
    QAction *action_Color_green;
    action_Color_green = colorMenu->addAction(tr("绿色"));
    action_Color_green->setCheckable(true);
    toolBtn->setMenu(colorMenu);                    //添加菜单
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);            //向工具栏添加QToolButton按钮
    QSpinBox *spinbox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinbox);

    //显示临时消息，2000ms即2s
    ui->statusBar->showMessage(tr("欢迎使用Qt!"), 2000);
    //创建标签，设置样式
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("hdzk");
    ui->statusBar->addPermanentWidget(permanent);

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::on_action_New_triggered()
{
    //新建文本编辑器部件
    QTextEdit *edit = new QTextEdit(this);
    //使用QMdiArea类的addSubWindow()函数创建子窗口，以文本编辑器为中心部件
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}

void MyMainWindow::on_actionxians_triggered()
{
    ui->dockWidget->show();
}
