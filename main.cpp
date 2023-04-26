
#include <QApplication>
#include "ToDoAppForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ToDoAppForm form;

    form.show();

    return a.exec();
}
