#define MAX_ACCOUNTS 20

int debit(float amount, Account* account){
	//include check here to make sure client is in a valid customer session, otherwise error and return -1

	if(!account){
		//report error, NULL account passed
		return -1;
	}
	if (account->isf!=1){
		//report error, client not in session
		return -1;
	}
	if(amount<=0){
		//report error, negative number or zero passed
		return -1;
	}

	if(amount>account->balance){
		//report error, amount debited cannot exceed account balance
		return -1;
	}

	account->balance -= amount;
	return 0;
}

int credit(float amount, Account* account){
	//include check here to make sure client is in a valid customer session, otherwise error and return -1

	if(!account){
		//report error, NULL account passed
		return -1;
	}

	if (account->isf!=1){
		//report error, client not in session
		return -1;
	}

	if(amount<=0){
		//report error, negative number or zero passed
		return -1;
	}

	account->balance += amount;
	return 0;
}

float currentbalance(Account* account){
	//include check here to make sure client is in a valid customer session, otherwise error and return -1
	if(!account){
		//report error, NULL account passed
		return -1.0;
	}
	if (account->isf!=1){
		//report error, client not in session
		return -1;
	}
	return account->balance;
}
