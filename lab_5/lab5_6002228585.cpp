// Bryan Thiha 	
// 6002228585
// 03/09/20


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream outfile;


struct Profit
{
	double dollar;
	int duration;

};

class KWP
{
	public:

		Profit kwp_profit;

		KWP()
		{
			kwp_profit.dollar = 0;
			kwp_profit.duration = 0;
	
			outfile << "Kanye West Object has been constructed" << endl;
			
		}


		~KWP()
		{
			
			outfile << "Kanye West Object has been destructed " << endl;
			outfile.close();
		}



		double P_value(double Z, double f1, double f2, double f3)
		{
			if(Z == 1)
			{
				return f1;
			}
			else
			{
				return f1 + f2 + f3 + P_value(Z-1, f1, f2, f3);
			}
			
		}


		int C_value(double Z)
		{
			if(Z == 0)
			{
				return 0;
			}
			if(Z == 1)
			{
				return 1;
			}
			if(Z == 2)
			{
				return 2;
			}
			if(Z == 3)
			{
				return 4;
			}
			else
			{
				return C_value(Z-1) + C_value(Z-2) + C_value(Z-3);
			}
		}


		int GetProfit()
		{
			return kwp_profit.dollar;
		}


		void SetProfit(double weeks, double f1, double f2, double f3)
		{
			 double avg_profit = (P_value(weeks, f1, f2, f3))/(C_value(weeks));
			 
			 kwp_profit.dollar = avg_profit;
		}
		
};



class KYP
{
	public:

		Profit kyp_profit;

		KYP()
		{
			kyp_profit.dollar = 0;
			kyp_profit.duration = 0;

			outfile << "Kourosh Yaghmaei Object has been constructed " << endl;
		}


		~KYP()
		{
			outfile << "Kourosh Yaghmaei Object has been destructed " << endl;
		}


		void SetProfit(double profit, double percentage)
		{
			 
			 kyp_profit.dollar = profit * (percentage/100);
		}

		int GetProfit()
		{
			return kyp_profit.dollar;
		}
		
};



int main()
{

	outfile.open("output.txt");

	KWP kw_profit;

	KYP ky_profit;
	
	double entry[7];

	double Z;
	int size = sizeof(entry)/sizeof(entry[0]);


	cout << "Enter the number of weeks: ";
	cin >> Z;

	while(1)
	{
		if(Z > 52 || Z < 0)
		{
			cout << "Invalid input!! " << endl;
			cout << "Try again: ";
			cin >> Z;
		}
		else
		{
			break;
		}
	}


	ifstream infile;	
	infile.open("input.txt");

	for(int i = 0; i < size; i++)
	{
		infile >> entry[i];
	}

	infile.close();



	double f1 = entry[1];
	double f2 = entry[3];
	double f3 = entry[5];
	double percentage = entry[6];


	kw_profit.SetProfit(Z, f1, f2, f3);

	double kanye_avg_profit = kw_profit.GetProfit();



	ky_profit.SetProfit(kanye_avg_profit, percentage);

	double kourosh_avg_profit = ky_profit.GetProfit();


	outfile << "KW's profit for Z number of weeks in average is estimated $" << kanye_avg_profit << ", out of which " << percentage << "%, " << "i.e., $" << kourosh_avg_profit << " is KY's." << endl;

}
