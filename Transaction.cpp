#include "Transaction.h"
//name: shahar solema
void Transaction::SetSource(Account* src){//set pointer to account src
	m_source = src;

}
void Transaction::SetDes(Account* dst){//set pointer to account des
	m_destination = dst;
}
void Transaction::SetAmount(double amount){//set amount to transaction
	m_amount = amount;

}
void Transaction::SetDate(const char* date){//set date to transaction
	if (date != NULL) {
		m_date = new char[strlen(date) + 1]; //new allocation to string array
		strcpy_s(m_date, strlen(date) + 1, date);
		//strcpy(m_date, date);
	}
}
Account* Transaction::GetSource() const {//source getter
	return m_source;
}
Account* Transaction::GetDes() const{//des getter
	return m_destination;
}
double Transaction::GetAmount() const{//amount getter
	return m_amount;
}
char* Transaction::GetDate() const{//date getter
	return m_date;
}

Transaction::Transaction(Account* s, Account* d, double amount, const char* date) {//paramerter constructor
	SetAmount(amount);
	SetDate(date);
	SetSource(s);
	SetDes(d);

}
Transaction::Transaction(const Transaction& other){//copy constructor
	SetAmount(other.GetAmount());
	SetDate(other.GetDate());
	SetSource(other.GetSource());
	SetDes(other.GetDes());
}