#include "Account.h"

void Account::SetPersons(Person** persons, int count) { // persons setter
    m_totalPersons = count;
    m_persons = new Person*[count]; // new allocation to person array
    for (int i = 0; i < count; i++) {
        m_persons[i] = new Person(persons[i]->GetName(), persons[i]->GetId()); // copying person to the new array
    }
}

void Account::SetAccountNumber(int number) { // account number setter
    m_accountNumber = number;
}

void Account::SetBalance(double balance) { // balance setter
    m_balance = balance;
}

void Account::SetTransactions(Transaction** newTransaction, int count) { // transaction setter
    int counter = GetNumOfTransactions();
    m_numberOfTransaction = count;
    m_transactionList = new Transaction*[count]; // new allocation
    for (int i = 0; i < count; i++) {
        if (i < counter && count > 1) {
            m_transactionList[i] = new Transaction(newTransaction[i]->GetSource(), newTransaction[i]->GetDes(), newTransaction[i]->GetAmount(), newTransaction[i]->GetDate()); // new transaction to array
        } else {
            m_transactionList[i] = new Transaction(NULL, NULL, 0, NULL);
        }
    }
}

Transaction** Account::GetTransactions() { // Transactions getter
    return m_transactionList;
}

int Account::GetNumOfTransactions() { // num of Transactions getter
    return m_numberOfTransaction;
}

Person** Account::GetPersons() const { // persons getter
    return m_persons;
}

int Account::GetTotalPersons() const { // total person getter
    return m_totalPersons;
}

int Account::GetAccountNumber() const { // account number getter
    return m_accountNumber;
}
