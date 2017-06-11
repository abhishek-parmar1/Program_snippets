// wap  to construct priority queues
#include <iostream>       
#include <queue>          
#include <vector>         
#include <functional>     // std::greater

class mycomparison
{
  bool reverse;
  
public:
	
  // parmeterized constructor
  mycomparison(const bool& revparam=false)
    {
	reverse=revparam;
	}
	
  // method for comparison	
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) 
		return (lhs>rhs); // for creating min heap using parameterized constructor
    else 
		return (lhs<rhs); // for default construtor create max heap
  }
  
};

int main ()
{
  int myints[]= {10,60,50,20};

  std::priority_queue<int> first; // blank priority queue
  
  std::priority_queue<int> second (myints,myints+4); // priority queue using array (max heap)
  
  std::priority_queue<int, vector<int>, greater<int> > third (myints,myints+4); // priority queue using greater<int> (min heap) 
  
  // using mycomparison:
  typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

  mypq_type fourth;                       // less-than comparison (create max heap)
  
  mypq_type fifth (mycomparison(true));   // greater-than comparison (create min heap)

  return 0;
}
