#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  std::vector<T> A;
  int m;
  PComparator c;
	void heapify_down(int i);
	void heapify_up(int i);
};

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_down(int index)
{
	int curr_index = index;
	unsigned int left = 2*index+1;
	unsigned int right = 2*index+2;
	unsigned int best = curr_index;
	if (left < A.size() && c(A[left], A[curr_index]))
	{
		best = left;
	}
	if (right < A.size() && c(A[right], A[best]))
	{
		best = right;
	}
	if (best != curr_index)
	{
		std::swap(A[curr_index], A[best]);
		heapify_down(best);
	}

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_up(int index)
{
	int parent_index = (index - 1) / 2;
	T& curr = A[index];
	T& parent = A[parent_index];
	if (index == 0 || !c(curr, parent))
	{
		return;
	}
	std::swap(curr, parent);
	heapify_up(parent_index);
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) 
	: m(m), c(c)
{

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}



template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::underflow_error("heap is empty");
  }
  return A[0];  //return top (first) element

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("heap is empty");
  }
  
	//move last to top
  std::swap(A[0], A[A.size()-1]);
	A.pop_back();
	//heap config 
	heapify_down(0);


}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return A.size() == 0;
	//true if 0 == 0
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
	return A.size();
	//returns size of heap
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
	//push item to back bc O(1)
	A.push_back(item);
	//trickle up
	heapify_up(A.size()-1);
}

#endif

