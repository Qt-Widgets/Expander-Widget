#include "dialog.h"
#include "ui_dialog.h"

#include "expanderwidget.h"

#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QTextEdit>
#include <QCheckBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QWidget *widget = new QWidget();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QLabel *isItOK = new QLabel("Is it OK?");
    QCheckBox *checkBox = new QCheckBox();
    hBoxLayout->addWidget(isItOK);
    hBoxLayout->addWidget(checkBox);
    widget->setLayout(hBoxLayout);


    ExpanderWidget *expanderWidget = new ExpanderWidget(this);
    expanderWidget->setExpanderTitle("Settings");
    expanderWidget->setExpanded(false);
    expanderWidget->addPage(widget);


    QFrame *horizontalLine = new QFrame();
    horizontalLine->setFrameShape(QFrame::HLine);
    horizontalLine->setObjectName("horizontalLine");
    horizontalLine->setFrameShadow(QFrame::Sunken);

    QLabel *description = new QLabel("Description");

    QTextEdit *textEdit = new QTextEdit();

    QVBoxLayout *verticalBoxLayout = new QVBoxLayout();
    verticalBoxLayout->addWidget(expanderWidget);
    verticalBoxLayout->addWidget(horizontalLine);
    verticalBoxLayout->addWidget(description);
    verticalBoxLayout->addWidget(textEdit);

    ui->frame->setLayout(verticalBoxLayout);
    ui->frame->setStyleSheet("QFrame#frame{border: 1px solid gray;}");
}

Dialog::~Dialog()
{
    delete ui;
}
