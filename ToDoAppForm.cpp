#include "ToDoAppForm.h"
#include "ui_ToDoAppForm.h"

ToDoAppForm::ToDoAppForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToDoAppForm), dataBase(QSqlDatabase::addDatabase("QSQLITE")), stopAddToDataBase(false)
{
    ui->setupUi(this);

    dataBase.setDatabaseName("./tasksDB");

    dataBase.open();

    QSqlQuery query(dataBase);

    query.exec("CREATE TABLE Tasks(taskName TEXT, date TEXT);");

    query.exec("SELECT * FROM Tasks");

    while (query.next())
    {
        ui->newTaskLineEdit->setText(query.value(0).toString());
        ui->dateTimeEdit->setDateTime(QDateTime::fromString(query.value(1).toString(), "dd.MM.yyyy HH:mm"));
        on_addNewTaskPushButton_pressed();
    }

    stopAddToDataBase = true;

    ui->newTaskLineEdit->clear();
    ui->dateTimeEdit->clear();

    setWindowTitle("Список задач");

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(600));
    ui->dateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime().addSecs(600));

    initStylesheet();
}

ToDoAppForm::~ToDoAppForm()
{
    delete ui;
}

void ToDoAppForm::initStylesheet()
{
    QFile fileStyle(":/styles/style.css");

    fileStyle.open(QFile::ReadOnly);

    setStyleSheet(QString::fromLatin1(fileStyle.readAll()));
}

void ToDoAppForm::addTaskToDataBase()
{
    QSqlQuery query(dataBase);

    query.prepare("INSERT INTO Tasks(taskName, date) VALUES (:taskName, :date)");
    query.bindValue(":taskName", ui->newTaskLineEdit->text());
    query.bindValue(":date", ui->dateTimeEdit->dateTime().toString("dd.MM.yyyy HH:mm"));

    query.exec();
}

void ToDoAppForm::deleteTaskFromDataBase(const QString& taskName, const QString& date)
{
    QSqlQuery query(dataBase);

    query.exec(QString("DELETE FROM Tasks WHERE taskName = \'%1\' AND date = \'%2\'").arg(taskName).arg(date));
}

void ToDoAppForm::on_addNewTaskPushButton_pressed()
{
    if (stopAddToDataBase)
         addTaskToDataBase();

    QVBoxLayout* pMainLayout = qobject_cast<QVBoxLayout*>(ui->allNewTasksContents->layout());

    QFrame* pHFrame = new QFrame();
    pHFrame->setFrameStyle(QFrame::StyledPanel);

    QHBoxLayout* pNewTask = new QHBoxLayout(pHFrame);
    pHFrame->setLayout(pNewTask);

    QFrame* pVFrame = new QFrame();
    QVBoxLayout* pTaskDetails = new QVBoxLayout(pVFrame);
    pTaskDetails->setObjectName("pTaskDetails");
    pVFrame->setLayout(pTaskDetails);

    QLabel* pTitleLabel = new QLabel(QString("Задача №%1").arg(pMainLayout->count()));
    pTaskDetails->addWidget(pTitleLabel);

    QLabel* pTaskLabel = new QLabel(ui->newTaskLineEdit->text());
    pTaskDetails->addWidget(pTaskLabel);

    QLabel* pDateLabel = new QLabel(ui->dateTimeEdit->dateTime().toString("dd.MM.yyyy HH:mm"));
    pTaskDetails->addWidget(pDateLabel);

    pNewTask->insertWidget(0, pVFrame);

    QSpacerItem* pSpacer = new QSpacerItem(100, 100, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    pNewTask->insertSpacerItem(1, pSpacer);

    QPushButton* pcmdDeleteButton = new QPushButton("Удалить");
    pNewTask->insertWidget(2, pcmdDeleteButton);

    pcmdDeleteButton->setProperty("CurrentTask", QVariant(QVariant::fromValue<QFrame*>(pHFrame)));

    pMainLayout->insertWidget(pMainLayout->count() - 1, pHFrame);

    QObject::connect(pcmdDeleteButton, SIGNAL(clicked(bool)), this, SLOT(slotDeleteTask()));

    QStringList colors = { "rgba(66, 165, 245,1.0)", "rgba(41, 182, 246,1.0)", "rgba(38, 198, 218,1.0)", "rgba(38, 166, 154,1.0)", "rgba(102, 187, 106,1.0)",
                           "rgba(156, 204, 101,1.0)", "rgba(212, 225, 87,1.0)", "rgba(255, 238, 88,1.0)", "rgba(255, 202, 40,1.0)", "rgba(255, 167, 38,1.0)"};

    const int randomValue = (((rand() % 50) % 100) % (colors.size() - 1));

    pHFrame->setObjectName("NewTask");
    pHFrame->setStyleSheet("#NewTask { border-radius: 10px; border: 1px solid black; background-color: " + colors[randomValue] + "; }");

    pTaskLabel->setObjectName("TaskName");
    pTaskLabel->setStyleSheet("#TaskName { font: bold 11pt black 'Verdana'; }");

    pcmdDeleteButton->setObjectName("DeleteBtn");
    pcmdDeleteButton->setStyleSheet("#DeleteBtn { color: white; background-color: #ff2264; border-color: #b91043; }  #DeleteBtn:hover{ background-color: #b91043; border-color: #ff2264; }");

    ui->newTaskLineEdit->clear();
}

void ToDoAppForm::on_dateTimeEdit_dateTimeChanged(const QDateTime& dateTime)
{
    ui->newDateTextLabel->setText("Дата, до которой необходимо выполнить задачу: " + dateTime.toString("dd.MM.yyyy HH:mm"));
}

void ToDoAppForm::slotDeleteTask()
{
    QPushButton* pFromButton = dynamic_cast<QPushButton*>(sender());

    QVariant var = pFromButton->property("CurrentTask");

    QFrame* pTaskHBox = qvariant_cast<QFrame*>(var);

    QVBoxLayout* layout = pTaskHBox->findChild<QVBoxLayout*>("pTaskDetails");

    QLabel* labelTaskName = qobject_cast<QLabel*>(layout->itemAt(1)->widget());
    QLabel* labelDateTime = qobject_cast<QLabel*>(layout->itemAt(2)->widget());

    deleteTaskFromDataBase(labelTaskName->text(), labelDateTime->text());

    pTaskHBox->deleteLater();

    delete pTaskHBox;
}

