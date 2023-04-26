/********************************************************************************
** Form generated from reading UI file 'ToDoAppForm.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODOAPPFORM_H
#define UI_TODOAPPFORM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToDoAppForm
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *titleBarFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *titleText;
    QSpacerItem *horizontalSpacer_2;
    QFrame *contentFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *addToDoList;
    QHBoxLayout *horizontalLayout_2;
    QFrame *addLeft;
    QVBoxLayout *verticalLayout_3;
    QLabel *newTaskTextLabel;
    QLineEdit *newTaskLineEdit;
    QDateTimeEdit *dateTimeEdit;
    QLabel *newDateTextLabel;
    QFrame *addRight;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addNewTaskPushButton;
    QScrollArea *allNewTasksScrollArea;
    QWidget *allNewTasksContents;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ToDoAppForm)
    {
        if (ToDoAppForm->objectName().isEmpty())
            ToDoAppForm->setObjectName("ToDoAppForm");
        ToDoAppForm->resize(600, 593);
        verticalLayout = new QVBoxLayout(ToDoAppForm);
        verticalLayout->setObjectName("verticalLayout");
        titleBarFrame = new QFrame(ToDoAppForm);
        titleBarFrame->setObjectName("titleBarFrame");
        titleBarFrame->setFrameShape(QFrame::StyledPanel);
        titleBarFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(titleBarFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(235, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        titleText = new QLabel(titleBarFrame);
        titleText->setObjectName("titleText");

        horizontalLayout->addWidget(titleText);

        horizontalSpacer_2 = new QSpacerItem(235, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(titleBarFrame);

        contentFrame = new QFrame(ToDoAppForm);
        contentFrame->setObjectName("contentFrame");
        contentFrame->setFrameShape(QFrame::StyledPanel);
        contentFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(contentFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        addToDoList = new QFrame(contentFrame);
        addToDoList->setObjectName("addToDoList");
        addToDoList->setFrameShape(QFrame::StyledPanel);
        addToDoList->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(addToDoList);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        addLeft = new QFrame(addToDoList);
        addLeft->setObjectName("addLeft");
        addLeft->setFrameShape(QFrame::StyledPanel);
        addLeft->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(addLeft);
        verticalLayout_3->setObjectName("verticalLayout_3");
        newTaskTextLabel = new QLabel(addLeft);
        newTaskTextLabel->setObjectName("newTaskTextLabel");

        verticalLayout_3->addWidget(newTaskTextLabel);

        newTaskLineEdit = new QLineEdit(addLeft);
        newTaskLineEdit->setObjectName("newTaskLineEdit");

        verticalLayout_3->addWidget(newTaskLineEdit);

        dateTimeEdit = new QDateTimeEdit(addLeft);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setDate(QDate(2023, 1, 1));
        dateTimeEdit->setMinimumDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setCalendarPopup(true);

        verticalLayout_3->addWidget(dateTimeEdit);

        newDateTextLabel = new QLabel(addLeft);
        newDateTextLabel->setObjectName("newDateTextLabel");

        verticalLayout_3->addWidget(newDateTextLabel);


        horizontalLayout_2->addWidget(addLeft);

        addRight = new QFrame(addToDoList);
        addRight->setObjectName("addRight");
        addRight->setFrameShape(QFrame::StyledPanel);
        addRight->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(addRight);
        verticalLayout_4->setObjectName("verticalLayout_4");
        addNewTaskPushButton = new QPushButton(addRight);
        addNewTaskPushButton->setObjectName("addNewTaskPushButton");

        verticalLayout_4->addWidget(addNewTaskPushButton);


        horizontalLayout_2->addWidget(addRight);


        verticalLayout_2->addWidget(addToDoList);

        allNewTasksScrollArea = new QScrollArea(contentFrame);
        allNewTasksScrollArea->setObjectName("allNewTasksScrollArea");
        allNewTasksScrollArea->setWidgetResizable(true);
        allNewTasksContents = new QWidget();
        allNewTasksContents->setObjectName("allNewTasksContents");
        allNewTasksContents->setGeometry(QRect(0, 0, 560, 367));
        verticalLayout_5 = new QVBoxLayout(allNewTasksContents);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer = new QSpacerItem(20, 371, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        allNewTasksScrollArea->setWidget(allNewTasksContents);

        verticalLayout_2->addWidget(allNewTasksScrollArea);


        verticalLayout->addWidget(contentFrame);


        retranslateUi(ToDoAppForm);

        QMetaObject::connectSlotsByName(ToDoAppForm);
    } // setupUi

    void retranslateUi(QWidget *ToDoAppForm)
    {
        ToDoAppForm->setWindowTitle(QCoreApplication::translate("ToDoAppForm", "Form", nullptr));
        titleText->setText(QCoreApplication::translate("ToDoAppForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\267\320\260\320\264\320\260\321\207", nullptr));
        newTaskTextLabel->setText(QCoreApplication::translate("ToDoAppForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        newTaskLineEdit->setPlaceholderText(QCoreApplication::translate("ToDoAppForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        newDateTextLabel->setText(QCoreApplication::translate("ToDoAppForm", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \320\267\320\260\320\264\320\260\321\207\320\270:", nullptr));
        addNewTaskPushButton->setText(QCoreApplication::translate("ToDoAppForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToDoAppForm: public Ui_ToDoAppForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOAPPFORM_H
