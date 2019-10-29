#include "widget.h"
#include "ui_widget.h"

#include "expanderwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>

#include "dialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Expander Widget");

    QTextEdit *textEdit1 = new QTextEdit("Text Edit 1");
    QTextEdit *textEdit2 = new QTextEdit("Text Edit 2");
    QTextEdit *textEdit3 = new QTextEdit("Text Edit 3");

    ExpanderWidget *expanderWidget1 = new ExpanderWidget(this);
    expanderWidget1->setExpanderTitle("Expander-1 Title");
    expanderWidget1->setExpanded(false);
    expanderWidget1->addPage(textEdit1);

    ExpanderWidget *expanderWidget2 = new ExpanderWidget(this);
    expanderWidget2->setExpanderTitle("Expander-2 Title");
    expanderWidget2->addPage(textEdit2);
    expanderWidget2->addPage(textEdit3);
    expanderWidget2->setCurrentIndex(0);

    QVBoxLayout *verticalBoxLayout = new QVBoxLayout();
    verticalBoxLayout->addWidget(expanderWidget1);
    verticalBoxLayout->addWidget(expanderWidget2);
    ui->frame->setLayout(verticalBoxLayout);
    ui->frame->setStyleSheet(".QFrame{border: 1px solid gray;}");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    Dialog *dialog = new Dialog(this);
    dialog->show();
}
