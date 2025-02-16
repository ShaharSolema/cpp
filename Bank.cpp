#include "Bank.h"

void Bank::SetBankName(const char* name) { // bank name setter
    int len = strlen(name) + 1;
    m_name = new char[len]; // new allocation to string array
    strcpy_s(m_name, len, name);
}

void Bank::SetAccount(Account** account, int numbeOfAccounts) { // account setter
    m_numbeOfAccounts = numbeOfAccounts;
    m_account = new Account*[numbeOfAccounts]; // new allocation
    for (int i = 0; i < numbeOfAccounts; i++) {
        m_account[i] = new Account(account[i]->GetPersons(), account[i]->GetTotalPersons(), account[i]->GetBalance()); // setting new account to array
        m_account[i]->SetAccountNumber(account[i]->GetAccountNumber());
        m_account[i]->SetTransactions(account[i]->GetTransactions(), account[i]->GetNumOfTransactions());
    }
}

void Bank::SetTotal(double total) { // balance setter
    m_totalBalance = total;
}

void Bank::SetCode(int code) { // code setter
    m_bankCode = code;
}

const char* Bank::GetBankName() const { // bank name getter
    return m_name;
}

Account** Bank::GetAccounts() const { // array accounts getter
    return m_account;
}

int Bank::GetNumberOfAccounts() const { // return number of accounts
    return m_numbeOfAccounts;
}

double Bank::GetTotal() const { // return balance of the bank
    return m_totalBalance;
}

int Bank::GetCode() const { // return code of the bank
    return m_bankCode;
}

Bank::Bank() : m_bankCode(0), m_name(NULL), m_account(NULL), m_numbeOfAccounts(0), m_totalBalance(0) {} // default constructor

Bank::Bank(const char* name, int code) : m_account(NULL), m_numbeOfAccounts(0), m_totalBalance(0) { // constructor by parameters
    SetBankName(name);
    SetCode(code);
}

Bank::~Bank() { // destructor
    delete[] m_account;
    delete[] m_name;
}

void Bank::AddAccount(const Account& account) { // adding account to the bank
    int flag = 1;
    for (int i = 0; i < GetNumberOfAccounts(); i++) {
        if (GetAccounts()[i]->GetAccountNumber() == account.GetAccountNumber()) { // checking if account exists
            flag = 0;
            break;
        }
    }
    if (flag) { // account doesn't exist
        Account** temp = new Account*[GetNumberOfAccounts() + 1];
        for (int j = 0; j < GetNumberOfAccounts(); j++) {
            temp[j] = new Account(GetAccounts()[j]->GetPersons(), GetAccounts()[j]->GetTotalPersons(), GetAccounts()[j]->GetBalance()); // new temp to save all values
            temp[j]->SetTransactions(GetAccounts()[j]->GetTransactions(), GetAccounts()[j]->GetNumOfTransactions());
        }
        temp[GetNumberOfAccounts()] = new Account(account);
        SetAccount(temp, GetNumberOfAccounts() + 1); // setting the new array temp to account
        delete[] temp;
    }
    SetTotal(account.GetBalance() + GetTotal());
}

void Bank::AddAccount(const Person& per, double amount) { // adding new account to the bank
    AddAccount(Account(per, amount));
    SetTotal(GetTotal() + amount);
}

void Bank::AddPerson(const Person& newPerson, const Account& account, double amount) { // adding person to the accounts array
    for (int i = 0; i < GetNumberOfAccounts(); i++) {
        if (GetAccounts()[i]->GetAccountNumber() == account.GetAccountNumber()) { // checking if person account number exists in array
            for (int j = 0; j < GetAccounts()[i]->GetTotalPersons(); j++) {
                if (GetAccounts()[i]->GetPersons()[j]->GetId() != newPerson.GetId()) { // checking if person not exists in array of persons in the account
                    m_account[i]->AddPerson(newPerson, amount);
                    SetTotal(GetTotal() + amount);
                }
            }
        }
    }
}

void Bank::DeleteAccount(const Account& account) { // delete account
    for (int i = 0; i < GetNumberOfAccounts(); i++) {
        if (GetAccounts()[i]->GetAccountNumber() == account.GetAccountNumber()) { // if account exists in array
            if ((i == 0) && (GetNumberOfAccounts() == 1)) { // if account is the only person in array
                delete[] m_account;
                m_numbeOfAccounts = 0;
            } else {
                delete m_account[i];
                m_numbeOfAccounts--;
                i--;
            }
        }
    }
    SetTotal(GetTotal() - account.GetBalance());
}

void Bank::DeletePerson(const Person& p) { // delete person from accounts
    for (int i = 0; i < GetNumberOfAccounts(); i++) {
        GetAccounts()[i]->DeletePerson(p); // going to function in account.cpp
        if (GetAccounts()[i]->GetTotalPersons() == 0) { // checking if array of person in account is empty
            SetTotal(GetTotal() - GetAccounts()[i]->GetBalance());
            for (int j = i; j < GetNumberOfAccounts() - 1; j++) { // loop that deletes the last place in array
                m_account[j] = GetAccounts()[j + 1];
            }
            delete m_account[GetNumberOfAccounts() - 1];
            m_numbeOfAccounts--;
            i--;
        }
    }
}
