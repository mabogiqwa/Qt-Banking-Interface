#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QPushButton>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>
#include <vector>
#include <memory>
#include <iostream>
#include <QWidget>

enum class TransactionType
{
  DEPOSIT, WITHDRAWAL
};

class Transaction
{
public:
    Transaction();

    Transaction(const QDateTime& dateTime1, double amount1, TransactionType type1);

    QDateTime getDateTime() const;

    double getAmount() const;

    TransactionType getType() const;

    QString getTypeString() const;

    QString formatOutput() const;
private:
    QDateTime dateTime;
    double amount;
    TransactionType type;
};

#endif // TRANSACTION_H
