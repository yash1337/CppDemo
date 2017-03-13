#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> 
#include <random>
#include <iterator>
#include <chrono>

using std::cout;using std::cin;using std::endl;
using std::vector; using std::unique;using namespace std::chrono;
int main()
{
	vector<int> in;
	vector<int> randomNumber;
	for (int i=0;i<100000000;i++)
	{
		randomNumber.push_back(i);
	}
	//auto engine = std::default_random_engine{};
	//std::shuffle(std::begin(randomNumber), std::end(randomNumber), engine);
	
	cout<<"Size of the vector: "<<randomNumber.size()<<endl;
	cout<<endl;
	int numToFind=-1;
	bool flag=false;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (unsigned int i=0;i<randomNumber.size();i++)
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
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	cout<< "CPU time for linear search for worst case: " << duration_cast<microseconds>( t2 - t1 ).count() << "ns" << std::endl;
	cout<<"\n"<<endl;
	
	
	t1 = high_resolution_clock::now();
	if(std::binary_search(randomNumber.begin(),randomNumber.end(),numToFind))
		cout<<"Found!!!!!!"<<endl;
	else
		cout<<"Worst case found. Element not in vector"<<endl;
	t2 = high_resolution_clock::now();
	cout << "CPU time for binary search search for worst case: " << duration_cast<microseconds>( t2 - t1 ).count() << "ns" << endl;
	cout<<"\n"<<endl;
}
