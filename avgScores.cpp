#include<iostream>
using namespace std;

float average(int N, float quizScores[]);
int countHigh(int N, float quizScores[], float avg);

int main()
{
	int N=0;
	float quizScores[100];
	float avg;
	int aboveAvg;

	cout<<"Please enter the number of scores\n";
	cin>>N;
	cout<<"Please enter the quiz scores\n";
	for(int i=0;i<N;i++)
	{
		cin>>quizScores[i];
	}
	avg = average(N,quizScores);
	aboveAvg = countHigh(N, quizScores, avg);
	cout<<"The average: "<<avg<<endl;
	cout<<"The number of scores higher than average: "<<aboveAvg<<endl;

	system("pause");
	return 0;

}


float average(int N, float quizScores[])
{
	float avg=0, sum=0;
	
	for(int i=0;i<N;i++)
	{
		sum+=quizScores[i];
	}
	avg = sum / N;
	return avg;
}

int countHigh(int N, float quizScores[], float avg)
{
	int aboveavg=0;
	for(int i=0;i<N;i++)
	{
		if(quizScores[i]>avg)
		{
			aboveavg++;
		}
	}
	return aboveavg;

}

/*-----------------output--------------------
Please enter the number of scores
5
Please enter the quiz scores
73 82 91 76 70
The average: 78.4
The number of scores higher than average: 2
Press any key to continue . . .
--------------------------------------------*/
