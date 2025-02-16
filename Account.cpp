#include "Account.h"

void Account::SetPersons(Person** persons, int count) {// persons setter
	m_totalPersons = count;
	int i;
	m_persons = new Person * [count];// new allocation to person array
	
	for (i = 0; i < count; i++) {
			m_persons[i] = new Person(persons[i]->GetName(), persons[i]->GetId());//copying person to the new array.


	}

}
void Account::SetAccountNumber(int number) {//account number setter
	m_accountNumber = number;
}

void Account::SetBalance(double balance) {//balance setter.
	m_balance = balance;
}

void Account::SetTransactions(Transaction** newTransaction, int count) {//transaction setter
	int counter =GetNumOfTransactions();
	m_numberOfTransaction = count;
	int i;
	m_transactionList = new Transaction * [count];//new allocation
	
	for (i = 0; i < count; i++) {
		if (i<counter &&count>1)
			m_transactionList[i] = new Transaction(newTransaction[i]->GetSource(), newTransaction[i]->GetDes(),newTransaction[i]->GetAmount(), newTransaction[i]->GetDate());//new transaction to array
		else
			m_transactionList[i] = new Transaction(NULL, NULL,0,NULL);


	}

}

Transaction** Account::GetTransactions() {//Transactions getter
	return m_transactionList;
}

int Account::GetNumOfTransactions() {//num of Transactions getter
	return m_numberOfTransaction;
}

Person** Account::GetPersons() const {//persons getter
	return m_persons;
}

int	Account::GetTotalPersons()const { //total person getter
	return m_totalPersons;
}

int	Account::GetAccountNumber() const {//account number getter
	return m_accountNumber;
}

double Account::GetBalance() const {//balance getter
	return m_balance;
}

Account::Account() :m_persons(NULL), m_accountNumber(0), m_balance(0), m_numberOfTransaction(0), m_totalPersons(0), m_transactionList(NULL) {}//default constructor

Account::Account(Person** persons, int count, double balance):m_transactionList(NULL),m_balance(balance),m_numberOfTransaction(0) {//constructor by parameters.
	SetPersons(persons, count);
	int sum = 0;
	
	for (int i = 0; i < GetTotalPersons(); i++) {//uniqe way to set id
		sum += persons[i]->GetId();

	}
	SetAccountNumber(persons[0]->GetId()/100);
}

Account::Account(const Person& person, double balance):m_transactionList(NULL),m_numberOfTransaction(0) {//copy constructor and balance
	Person** temp = new Person * [1];
	temp[0] = new Person(person);//new Person** to save all the values
	SetPersons(temp, 1);
	delete[]temp;
	SetBalance(balance);
	SetAccountNumber(person.GetId() / 100);

}

Account::Account(const Account& other) {//copy constructor
	SetBalance(other.GetBalance());
	SetAccountNumber(other.GetAccountNumber());
	SetPersons(other.GetPersons(), other.GetTotalPersons());
	SetTransactions(other.m_transactionList, other.m_numberOfTransaction);
}

Account::~Account() {//distructor
		delete[]m_transactionList;
		if(GetTotalPersons()!=0)
			delete[]m_persons;
}

void Account::Withdraw(double amount, const char* date) {// withdraw function
	SetTransactions(GetTransactions(), GetNumOfTransactions() + 1);//array of transaction bigger by 1
	if (GetTransactions() != NULL) {
		GetTransactions()[GetNumOfTransactions() - 1]->SetDate(date);//set date
		GetTransactions()[GetNumOfTransactions() - 1]->SetAmount(amount);//set amount to new transaction
	}
	SetBalance(GetBalance() - amount);//balance minus amount 
}

void Account::Deposit(double amount, const char* date) {//deposite function
	SetTransactions(GetTransactions(), GetNumOfTransactions() + 1);//array of transaction bigger by 1
	if (GetTransactions() != NULL) {
		GetTransactions()[GetNumOfTransactions() - 1]->SetDate(date);//set date
		GetTransactions()[GetNumOfTransactions() - 1]->SetAmount(amount);
	}

	SetBalance(GetBalance() + amount);//balance plus amount


}

void Account::AddPerson(const Person& newPerson, double	amount) {//add person to the array of persons
	int flag = 1;
	int i, j;
	for (i = 0; i < GetTotalPersons(); i++) {
		if (newPerson.GetId() == GetPersons()[i]->GetId()) {//checking if this person exist in the array
			flag = 0;
			break;
		}

	}
	if (flag) {//person doesnt exist in array,adding him to the end of the array
		SetBalance(GetBalance() + amount);
		Person** temp = new Person * [GetTotalPersons() + 1];
		
		for (j = 0; j < GetTotalPersons(); j++) {
			temp[j]= new Person (GetPersons()[j]->GetName(), GetPersons()[j]->GetId());//new Person to save all the values.
		}
		temp[j] = new Person(newPerson);
		SetPersons(temp, j+1);
		delete[]temp;
		
		if (GetTotalPersons() == 1)//setting the account number of the first person
			SetAccountNumber(GetPersons()[0]->GetId() / 100);

	}
}

void Account::DeletePerson(const Person& oldPerson) {//delete person from array
	int j, i;
	
	for ( i = 0; i < GetTotalPersons(); i++) {
		if (GetPersons()[i]->GetId() == oldPerson.GetId()) {//if person exisst in array
			if ((i ==0)&& (GetTotalPersons() == 1)) {//if person is the only person in array
				delete[]m_persons;
				m_totalPersons = 0;
			}

			else {
				delete m_persons[i];//deleting the person from array.
				m_totalPersons--;
				i--;
			}
		}

	}
}
void Account::AddTransaction(const Transaction& newTransaction) {//adding new transaction
	newTransaction.GetDes()->SetTransactions(newTransaction.GetDes()->GetTransactions(), newTransaction.GetDes()->GetNumOfTransactions() + 1);
	newTransaction.GetDes()->GetTransactions()[newTransaction.GetDes()->GetNumOfTransactions() - 1] = new Transaction(newTransaction);//adding new transaction to the account
	newTransaction.GetDes()->SetBalance(newTransaction.GetAmount() + newTransaction.GetDes()->GetBalance());
	
	if (newTransaction.GetDes() != newTransaction.GetSource()) {//if its not the sasme account, adding new transaction to the source
		newTransaction.GetSource()->SetTransactions(newTransaction.GetSource()->GetTransactions(),newTransaction.GetSource()->GetNumOfTransactions()+1);
		newTransaction.GetSource()->GetTransactions()[newTransaction.GetSource()->GetNumOfTransactions() - 1] = new Transaction(newTransaction);
		newTransaction.GetSource()->SetBalance(newTransaction.GetSource()->GetBalance()-newTransaction.GetAmount() );

		}
	}

	void Account::clearTransactions() {//delete all transactions
		if(m_transactionList!=NULL)
			delete[]m_transactionList;	
	}

	void Account::clearPersons() {//delete all array of persons
		if(GetTotalPersons()!=0)
			delete[]m_persons;
	}

