#include "std_lib_facilities.h"
#include "Person.h"

using namespace std;



int main()
{
/*
	Person p1;
	p1.name="Goofy";
	p1.age=63;

	cout<<p1.name<<" "<<p1.age<<endl;
	cout<<p1<<endl;
*/

	Person p2;

	cout<<"Give name and age:"<<endl;
	cin>>p2;
	cout<<p2<<endl;

	cout<<"Give names to the vector:"<<endl;

	vector<Person> people;
	Person temp;
	int numOfPeople=0;
	while(cin>>temp)
	{
		people.push_back(temp);
		cout<<people[numOfPeople]<<endl;
		++numOfPeople;
	}


	return 0;
}