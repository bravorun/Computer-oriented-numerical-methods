#include <iostream>
using namespace std;
class polynomial {
public:
	double coeficient;
	int exponent;
	polynomial* next;
};
polynomial* create(double coeficient, int exponent) {
	polynomial* temp = new polynomial();
	if (temp == NULL)
		return 0;
	else{
	temp->coeficient=coeficient;
	temp->exponent = exponent;
	temp->next = NULL;
	return temp;
	}
}
void insert(polynomial**head, int coeficient, int exponent) {
	polynomial* temp = create(coeficient, exponent);
	temp->next = *head;
	*head = temp;
}
double calculate(polynomial** head, double x,int degree) {
	double cal=0;
	int i = 0;
	polynomial* temp = *head;
	while (temp!= NULL) {
		cal+= temp->coeficient * pow(x, i);
		i++;
		temp = temp->next;
	}
	return cal;
}
float bisection(polynomial** head, int degree) {
	double a, b,sa,sb,mid,smid;
	do {
		cout << "\nEnter two initial value:";
		cin >> a >> b;
		sa =calculate(head, a, degree);
		sb = calculate(head, b, degree);
	} while (sa*sb>0);
	double swap;
	if (sa < sb) {
		swap = a;
		a = b;
		b = swap;
	}
	do {
		mid = (a +b) / 2.0;
		smid = calculate(head, mid, degree);
		if (smid < 0) {
			b = mid;
		}
		else if (smid > 0)
			a = mid;
		cout << mid<<endl;
		cout << smid << endl;
	} while (smid!=0||smid>0.1);
		return mid;
}
int main(void) {
	int highest_degree;
	double coef;
	polynomial* head = NULL;
	cout << "Enter higest degree of polynomial:";
	cin >> highest_degree;
	for (int i = highest_degree; i >=0; i--) {
		cout << "\nEnter coeficient for degree " << i<<":";
		cin >> coef;
		insert(&head, coef, i);
	}
	cout << bisection(&head, highest_degree);
}