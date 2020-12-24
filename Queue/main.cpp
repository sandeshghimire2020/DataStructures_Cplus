#include <iostream>
#include<iomanip>
#include<cstdlib>
#include "queue.h"
#include "queue.cpp"
#include <cmath>
using namespace std;

int main ()
{

	int ARV_PROB; //variable for probability
	int MAX_TRANS_TIME;//maximum transaction time
	int DURATION;//duration of the simulation
	int server;//number of servers

    //asking input to the users
	cout<<setw(4)<<"----Enter these parameters of the simulation:----"<<endl;
	cout<<"The number of queue/server pairs: ";
	cin>>server;
	cout<<"The probability that a customer arrives in one tick (%): ";
	cin>>ARV_PROB;
	cout<<"The maximum duration of a transaction in ticks: ";
	cin>>MAX_TRANS_TIME;
	cout<<"The duration of the simulation in ticks: ";
	cin>>DURATION;
    Queue line[server];//declare the array of queue
	int trans_time[server];//array of transaction time
	for(int temp=0; temp<server; ++temp)//starting loop for initializing trans_time
	{
		trans_time[temp] = 0;
	}
    //declaring some variables and initializing them
	int count = 0;
	int time_e;
	int wait_sum = 0;
	int Count = 0;
	int seed;
	int Remaining = 0;
	int High = 0;
    //asking seed to the user
	cout<<"Enter a random number seed : ";
	cin>>seed;
	cout<<endl;
	srand(seed);//randomizing the seed

	for(int time=1; time<DURATION; ++time)//starting the big loop
	{
		int temp =0;
		if(rand()%100 < ARV_PROB)//checking if the value is less then the original probability
		{
			int index = 1;
			while (index < server)//looping to select the available queue and storing data
			{
				if(line[temp].Size() > line[index].Size()) //checking which queue is short
				{
					temp = index;
				}
				++index;//increasing the value of index
			}
			line[temp].enqueue(time);//value goes into queue
		}
		for (int i = 0;i<server; ++i)//starting loop
		{
			if(trans_time[i] == 0)//check is transcation time is 0 or not
			{
				if(!line[temp].empty())//checking if the queue is empty or not
				{
					time_e = line[temp].dequeue();//put the value in time_e by dequeuing the data
					wait_sum += time - time_e;//finding out the wait time
					Count = time - time_e;//
					if(Count>High)//check if count is greater then high
						High = Count;
					++count;
					trans_time[i] = rand() % MAX_TRANS_TIME + 1;//randomizing the trans time again
				}
			}
			else//if the case is not satisfied
			--trans_time[i];//decrease the value of trans time
			cout<<endl;
	 	}
			cout<<time<<"::";//output the time
			for(int j = 0; j<server; ++j)//loop to display the queue
			{
				cout<<setw(4)<<trans_time[j]<<setw(4)<<line[j]<<endl;
			}
		}
	for(int i = 0; i<server; ++i)//loop to find out the remaining line
	{
		Remaining = Remaining + line[i].Size();
	}
	cout<<endl;
	//printing the outputs
	cout<<count<<" customers waited an average of "<<wait_sum/count<<" ticks."<<endl;
	cout<<"The longest time a customer waited was "<<High<<" ticks."<<endl;
	cout<<Remaining<<" customers remain in the lines. "<<endl;
	return 0;
}
