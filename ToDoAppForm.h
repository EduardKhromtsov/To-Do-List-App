#ifndef TODOAPPFORM_H
#define TODOAPPFORM_H

#include <QWidget>
#include <QFile>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class ToDoAppForm;
}

class ToDoAppForm : public QWidget
{
    Q_OBJECT

public:
    explicit ToDoAppForm(QWidget* parent = nullptr);
    ~ToDoAppForm() override;

private slots:
    void on_addNewTaskPushButton_pressed();

    void on_dateTimeEdit_dateTimeChanged(const QDateTime& dateTime);

    void slotDeleteTask();

private:
    Ui::ToDoAppForm *ui;
    QSqlDatabase dataBase;
    bool stopAddToDataBase;

private:
    void initStylesheet();

    void addTaskToDataBase();

    void deleteTaskFromDataBase(const QString& taskName, const QString& date);
};

#endif // TODOAPPFORM_H
