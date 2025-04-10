#ifndef BANKINGTRANSACTIONWINDOW_H
#define BANKINGTRANSACTIONWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

#include "transaction.h"
#include "transactionlist.h"

class BankingTransactionWindow : public QWidget
{
    Q_OBJECT

public:
    BankingTransactionWindow(QWidget *parent = nullptr);
    void updateBalanceDisplay();
    ~BankingTransactionWindow();
private slots:
    void onDeposit();
    void onWithdrawal();
    void onToFile();
private:
    QDoubleSpinBox *m_amountSpinBox;
    QLabel *balanceLabel;
    double currentBalance;
};
#endif // BANKINGTRANSACTIONWINDOW_H
