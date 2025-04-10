#include "bankingtransactionwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    BankingTransactionWindow window;
    window.show();
    return app.exec();
}
