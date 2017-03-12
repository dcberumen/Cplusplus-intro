
#ifndef arraytemp_assign_h
#define arraytemp_assign_h

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class FileTemp
{
private: int x;
		 string Date;
		 int amount;
		 float hightemp[100], lowtemp[100];
		 float temp1[100], temp2[100];
		 float avghigh, avglow, max, min;
public:
	FileTemp(){x=0;};
	void readfile();
	void maxmin();
	void averages();
	void histogram();
	~FileTemp(){};
};

void FileTemp::readfile()
{
	ifstream inputFile;
	inputFile.open("temperature.txt");

	getline(inputFile,Date);
	//cout<<Date<<endl;
	inputFile >> amount;
	//cout<<amount<<endl;
	for(int i=0;i<amount;i++)
	{
		inputFile >> temp1[i] >> temp2[i];
		if(temp1[i] > temp2[i])
		{
			hightemp[i] = temp1[i];
			lowtemp[i] = temp2[i];
		}
		else
		{
			hightemp[i] = temp2[i];
			lowtemp[i] = temp1[i];
		}

		//cout<<temp1[i]<<' '<<temp2[i]<<endl;
	}
	inputFile.close();
}
void FileTemp::maxmin()
{
	max = hightemp[0];
	min = lowtemp[0];
	for(int i=1;i<amount;i++)
	{
		if (hightemp[i]>max)
		{
			max = hightemp[i];
		}
		if (lowtemp[i]<min)
		{
			min = lowtemp[i];
		}

	}
	//cout<< "The max temp for "<<Date<<" is "<<max<<endl;
	//cout<< "The min temp for "<<Date<<" is "<<min<<endl;
}

void FileTemp::averages()
{
	cout<<fixed<<showpoint<<setprecision(2);
	avghigh = 0;
	avglow = 0;
	for(int i=0;i<amount;i++)
	{
		avghigh += hightemp[i];
		avglow += lowtemp[i];
	}
	avghigh = avghigh/amount;
	avglow = avglow/amount;
	//cout<< "The average high temp for "<<Date;
	//cout<< " is "<<avghigh<<endl;
	//cout<< "The average low temp for "<<Date;
	//cout<< " is "<<avglow<<endl;
}
void FileTemp::histogram()
{
	ofstream report;
	string range[12] = {"  <0|", " <=9|","<=19|","<=29|","<=39|","<=49|","<=59|","<=69|","<=79|","<=89|","<=99|"," >99|"};

	report.open("report.txt");

	report << "Temperatures on "<<Date<<endl;
	report << showpoint << fixed << setprecision(2) << "Average High: " <<avghigh<<" F\n";
	report << "Average Low: "<<avglow<<" F\n";
	report << setprecision(0) << "Highest Temperature for the day: "<<max<< "F\n";
	report << "Lowest Temperature for the day: "<<min<<" F\n\n";
	report << "Histogram for high temperatures\n";
	report << "----------------------------------\n";
	for(int i = 0; i<12; i++)
	{
		report <<range[i];
		switch(i)
		{
		case 0: for(int i=0;i<amount;i++)
				{
					if(hightemp[i]<0)
					{
					report<<'*';
					}
				}
				break;
		case 1: for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>0 && hightemp[i]<=9)
					{
					report<<'*';
					}				
				}
				break;
		case 2: for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>9 && hightemp[i]<=19)
					{
						report<<'*';
					}
				}
				break;
		case 3: for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>19 && hightemp[i]<=29)
					{
						report<<'*';
					}
				}
				break;
		case 4: for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>29 && hightemp[i]<=39)
					{
						report<<'*';
					}
				}
				break;
		case 5:for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>39 && hightemp[i]<=49)
					{
						report<<'*';
					}
				}
				break;
		case 6:for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>49 && hightemp[i]<=59)
					{
						report<<'*';
					}
				}
				break;
		case 7:for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>59 && hightemp[i]<=69)
					{
						report<<'*';
					}
				}
				break;
		case 8: for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>69 && hightemp[i]<=79)
					{
						report<<'*';
					}
				}
				break;
		case 9: for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>79 && hightemp[i]<=89)
					{
						report<<'*';
					}
				}
				break;
		case 10: for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>89 && hightemp[i]<=99)
					{
						report<<'*';
					}
				}
				break;
		case 11:for(int i = 0; i<amount;i++)
				{
					if(hightemp[i]>99)
					{
						report<<'*';
					}
				}
				break;
		}
		report<<endl;
	}
	report.close();
}
#endif
