/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_17;
    QLabel *pointsLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(700, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(Widget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(340, 20, 341, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(gridLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        QFont font;
        font.setPointSize(20);
        label_1->setFont(font);
        label_1->setFrameShape(QFrame::Box);
        label_1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Box);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Box);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::Box);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setFrameShape(QFrame::Box);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setFrameShape(QFrame::Box);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setFrameShape(QFrame::Box);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setFrameShape(QFrame::Box);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setFrameShape(QFrame::Box);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setFrameShape(QFrame::Box);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 2, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setFrameShape(QFrame::Box);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setFrameShape(QFrame::Box);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 2, 3, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setFrameShape(QFrame::Box);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);
        label_14->setFrameShape(QFrame::Box);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 3, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);
        label_15->setFrameShape(QFrame::Box);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 3, 2, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);
        label_16->setFrameShape(QFrame::Box);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 3, 3, 1, 1);

        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(520, 400, 160, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 550, 250, 20));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 250, 530));
        label->setFrameShape(QFrame::Box);
        label->setText(QStringLiteral(""));
        label->setTextFormat(Qt::PlainText);
        label_17 = new QLabel(Widget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(340, 450, 111, 31));
        label_17->setFont(font);
        pointsLabel = new QLabel(Widget);
        pointsLabel->setObjectName(QStringLiteral("pointsLabel"));
        pointsLabel->setGeometry(QRect(330, 490, 131, 81));
        QFont font1;
        font1.setPointSize(30);
        pointsLabel->setFont(font1);
        pointsLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);
        QObject::connect(pushButton_5, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Boggle", 0));
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        pushButton->setText(QApplication::translate("Widget", "Jugar", 0));
        pushButton_2->setText(QApplication::translate("Widget", "Jugar nuevo", 0));
        pushButton_3->setText(QApplication::translate("Widget", "Rotar", 0));
        pushButton_4->setText(QApplication::translate("Widget", "Resolver", 0));
        pushButton_5->setText(QApplication::translate("Widget", "Terminar", 0));
        lineEdit->setText(QString());
        label_17->setText(QApplication::translate("Widget", "Puntaje:", 0));
        pointsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
