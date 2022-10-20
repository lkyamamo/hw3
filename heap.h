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
  /// Add whatever helper functions and data members you need below
  std::vector<T> list; //0 based heap
  size_t m_;
  PComparator c_;



};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("underflow_error");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return list[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("underflow_error");

  }

  //set first to last value
  list[0] = list[list.size() - 1];
  list.pop_back();
  //trickle down
  size_t i = list.size() - 1;
  while(i < list.size()){
    //if no child stop
    if((m_*i) + 1 >= list.size())
    {
      break;
    }
    size_t child;
    //find best child

    //make first child the best initially
    child = (m_*i) + 1;
    
    size_t j = 2;
    //iterate over all children to find best child
    while((m_*i) + j < list.size() && j <= m_)
    {
      //if next child better than best child
      if(c_(list[(m_*i) + j], list[child]))
      {
        //make it new best child
        child = (m_*i) + j;
      }
      j++;
    }
    
    //if child "better" than parent
    if(c_(list[child], list[i]))
    {
      //swap
      T temp = list[i];
      list[i] = list[(i-1)/m_];
      list[(i-1)/m_] = temp;
    }else{
      break;
    }
    
    //go to swapped child
    i = child;
  }
}

template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
:m_(m)
,c_(c)
{
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  //add to the back
  list.push_back(item);

  //bubble up
  size_t i = list.size() - 1;
  while(i != 0){
    //if left "better" than right
    if(c_(list[i], list[(i-1)/m_]))
    {
      //swap
      T temp = list[i];
      list[i] = list[(i-1)/m_];
      list[(i-1)/m_] = temp;
    }else{
      break;
    }
    //go to parent
    i = (i-1)/m_;
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return list.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if(Heap<T,PComparator>::size() == 0)
  {
    return true;
  }
  else{
    return false;
  }
}

template<typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  /*
  for(size_t i = 0; i < list.size(); i++)
  {
    delete list[i];
  }
  list.clear();
  */
  list.clear();
}
#endif

