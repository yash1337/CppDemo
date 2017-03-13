#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> 
#include <iterator>
#include <chrono>

using std::cout;using std::cin;using std::endl;
using std::vector; using std::unique;using namespace std::chrono;
int main()
{
	//Creating the vector
	vector<int> in;
	vector<int> randomNumber;
	for (int i=0;i<100000000;i++)
	{
		randomNumber.push_back(i);
	}
	
	cout<<"Size of the vector: "<<randomNumber.size()<<endl;
	cout<<endl;	
	int numToFind=-1;
	bool flag=false;
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();//Starting time tracking
	for (unsigned int i=0;i<randomNumber.size();i++)//linear search algorithm
	{
		if (randomNumber.at(i)==numToFind)
		{
			cout<<"Found!!!!!!!"<<endl;
			flag=true;
			break;
		}
		
	}
	if (flag==false)
		cout<<"Worst case found. Element not in vector"<<endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();//ending time tracking	
	cout<< "CPU time for linear search for worst case: " << duration_cast<microseconds>( t2 - t1 ).count() << "ns" << std::endl;
	cout<<"\n"<<endl;
	
	
	t1 = high_resolution_clock::now();//Starting time tracking
	if(std::binary_search(randomNumber.begin(),randomNumber.end(),numToFind))
		cout<<"Found!!!!!!"<<endl;
	else
		cout<<"Worst case found. Element not in vector"<<endl;
	t2 = high_resolution_clock::now();//ending time tracking
	cout << "CPU time for binary search search for worst case: " << duration_cast<microseconds>( t2 - t1 ).count() << "ns" << endl;
	cout<<"\n"<<endl;
}
