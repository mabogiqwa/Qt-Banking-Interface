#include "transaction.h"

Transaction::Transaction()
{

}

Transaction::Transaction(const QDateTime& dateTime1, double amount1, TransactionType type1)
{
    dateTime = dateTime1;
    amount = amount1;
    type = type1;
}

QDateTime Transaction::getDateTime() const
{
    return dateTime;
}

double Transaction::getAmount() const
{
    return amount;
}

TransactionType Transaction::getType() const
{
    return type;
}

QString Transaction::getTypeString() const
{
    return (type == TransactionType::DEPOSIT) ? "Deposit" : "Withdrawal";
}

QString Transaction::formatOutput() const
{
    QString typeStr = (type == TransactionType::DEPOSIT) ? "Deposit" : "Withdrawal";
    return QString("%1: R%2 on %3 at %4").arg(typeStr).arg(amount,0,'f',2).arg(dateTime.toString("ddd MMM d")).arg(dateTime.toString("hh:mm:ss"));
}
