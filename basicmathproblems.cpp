#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class MathProblem{
	public:
		bool isanswercorrect(int corr, int ans){ //stores true if answer is correct, false otherwise
		if(ans==corr)
		return true;
		else if(ans!=corr)
		return false;
		}  
		virtual void setproblem(){ //dummy function
			return;
		}
		
		virtual void askuserforanswer(){ //dummy function
			return;
		}
		
		virtual void displayproblem(){ //dummy function
			return;
		}
	
};

class IntegerProblem:public MathProblem{ 
	public:
		int num1, num2; //operands of the addition
		int correctanswer; //correct answer of the addition
		int useranswer; //the user’s answer to the addition
		virtual void setproblem(){ //virtual member function which generates 2 random numbers (between 1100), assigns them to num1 and num2, and also assigns to correctanswer, the sum of num1 and num2. 
			srand(time(NULL));
			num1=rand() % 100 + 1;
			num2=rand() % 100 + 1;
			correctanswer=num1+num2;
		}
		virtual void displayproblem(){ //virtual member function which asks the problem to the user
			cout<<"Question is: "<<num1<<" + "<<num2<<" = ?"<<endl;
		}
		virtual void askuserforanswer(){ //virtual member function which asks the user for the answer of the addition, checks whether the answer is correct, and gives an appropriate response
			cout<<"Enter answer: ";
			cin>>useranswer;
			if(isanswercorrect(useranswer,correctanswer)==1)
			cout<<"Good Job!\n"<<endl;
			else
			cout<<"Sorry! The correct answer is "<<correctanswer<<"\n"<<endl;
		}
	
};

class FractionProblem:public MathProblem{
	public:
		int n1,d1;
		int n2,d2;
		int corrn,corrd;
		int usern, userd;
		virtual void setproblem(){ //virtual member function which generates the numerators and denominators of the 2 operands randomly (between 1-10),  and also assigns the sum of the operands to corrn and corrd (do not simplify the answer)
			srand(time(NULL));
			n1=rand() % 10 + 1;
			d1=rand() % 10 + 1;
			n2=rand() % 10 + 1;
			d2=rand() % 10 + 1;
			corrn=(n1*d2)+(n2*d1);
			corrd=(d2*d1);
			
		}
		virtual void displayproblem(){ //virtual member function which asks the problem to the user
			cout<<"Question is: "<<n1<<"/"<<d1<<" + "<<n2<<"/"<<d2<<" = ?"<<endl;
		}
		virtual void askuserforanswer(){ //virtual member function which asks the user for the answer(usern,userd) of the addition, checks whether the answer is correct, and gives an appropriate response
			cout<<"Enter answer: ";
			cin>>usern;
			cout<<"/";
			cin>>userd;
			if(isanswercorrect((usern/userd),(corrn/corrd))==1)
			cout<<"Good Job!\n"<<endl;
			else
			cout<<"Sorry! The correct answer is "<<corrn<<"/"<<corrd<<"\n"<<endl;
		}
};

int main()
{
	FractionProblem frac_q;
	IntegerProblem inte_q;
	int choice;
	while(true)
	{
	cout<<"Please choose type of addition problem:"<<endl;
	cout<<"    1. Fraction"<<endl<<"    2. Integer"<<endl<<"    3. Quit"<<endl<<"Choice: ";
	cin>>choice;
	if(choice==1)
	{
		frac_q.setproblem();
		frac_q.displayproblem();
		frac_q.askuserforanswer();	
	}
	else if(choice==2)
	{
		inte_q.setproblem();
		inte_q.displayproblem();
		inte_q.askuserforanswer();
	}
	else if(choice==3)
	return 0;
	}
	
	return 0;
}
