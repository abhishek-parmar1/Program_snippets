// wap to implement min heap using priority queue (different ways)
#include<iostream>
#include<queue>
#include<functional>
#include<vector>

using namespace std;

// 1st method by entering negative numbers in priority queue
/*
int main()
{	
	priority_queue <int> pq;
	pq.push(-30);
	pq.push(-20);
	pq.push(-10);
	pq.push(-5);
	pq.push(-1);
	
	while(!pq.empty())
	{
		cout<<-(pq.top())<<" ";
		pq.pop();
	}
	return 0;
}
*/

// 2nd method by using greater of functional headerfile for comparison
// because by default priority queue uses less for comparison
/*
int main()
{
	priority_queue < int, vector<int>, greater<int> > pq;
	pq.push(30);
	pq.push(20);
	pq.push(10);
	pq.push(5);
	pq.push(1);
	
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;

}
*/

// 3rd method by defining your own comparision method using structure or class
// by default operator  for comparison in priority queue is : <
// use > operator in comparison for creating  min heap
/*
struct compare
{
    bool operator()(const int & a, const int & b)
    {
        return a>b;
    }
};

int main()
{

    priority_queue<int,vector<int>,compare> pq;
    pq.push(30);
	pq.push(20);
	pq.push(10);
	pq.push(5);
	pq.push(1);

    while(!pq.empty())
    {
        int r = pq.top();
        pq.pop();
        cout<<r<<" ";
    }
    return 0;
}
*/

// 4th  method  Using custom structure or class you can use priority_queue in any order.
// Suppose, we want to sort people in descending order according to their salary and if tie then according to their age.

struct people
{
    int age,salary;

};

struct compare{
bool operator()(const people & a, const people & b)
    {
        if(a.salary==b.salary)
        {
            return a.age>b.age;
        }
        else
        {
            return a.salary>b.salary;
        }

	}
};

int main()
{

    priority_queue<people,vector<people>,compare> pq; //  using structure as underlying datatype
    
	people person1,person2,person3;
    
	person1.salary=100;
    person1.age = 50;
    person2.salary=80;
    person2.age = 40;
    person3.salary = 100;
    person3.age=40;


    pq.push(person1);
    pq.push(person2);
    pq.push(person3);

    while(!pq.empty())
    {
        people r = pq.top();
        pq.pop();
        cout<<r.salary<<" "<<r.age<<endl;
	}
	
	return 0;
}

/* NOTE : we can also overload the  default operator (<) of priority queue with operator (>) and directly use for min heap

struct people
{
int age,salary;

bool operator< (const people & p)const
{
    if(salary==p.salary)
    {
        return age>p.age;
    }
    else
    {
        return salary>p.salary;
    }
}

};

int main()
{

	priority_queue<people> pq;

	people person1,person2,person3;
	
	person1.salary=100;
	person1.age = 50;
	person2.salary=80;
	person2.age = 40;
	person3.salary = 100;
	person3.age=40;


	pq.push(person1);
	pq.push(person2);
	pq.push(person3);

	while(!pq.empty())
	{
	    people r = pq.top();
	    pq.pop();
	    cout<<r.salary<<" "<<r.age<<endl;
	}
	
	return 0;
}
