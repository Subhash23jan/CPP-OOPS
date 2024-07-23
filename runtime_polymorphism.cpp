#include <iostream>
#include <vector>
using namespace std;

class Payment {
public:
    virtual void processPayment(double amount) {
        cout << "Processed the generic payment of " << amount << endl;
    }
    void processingPayment(double amount){
    	cout << "Processing  payment of " << amount << endl;
	}
    virtual ~Payment() = default;
};

class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processed the credit card payment of " << amount << endl;
    }
   
};

class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processed the PayPal payment of " << amount << endl;
    }
};

class BitcoinPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processed the Bitcoin payment of " << amount << endl;
    }
};

int main() {
    Payment *payment;
    int n;
    cin>>n;
    if(n==0){
    	payment=new CreditCardPayment();
	}
	else if(n==1){
    	payment=new PayPalPayment();
	}
	else{
    	payment=new BitcoinPayment();
	}
	payment->processingPayment(100);
	payment->processPayment(100);
    return 0;
}

