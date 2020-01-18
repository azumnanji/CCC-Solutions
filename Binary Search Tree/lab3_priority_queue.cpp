#include "lab3_priority_queue.hpp"

using namespace std;

// PURPOSE: Parametric constructor 
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
	capacity = n_capacity+1;
	heap = new TaskItem*[capacity];
	size = 0;
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
	for (int i = 0; i < capacity; i++)
	{
		delete heap[i];
	}
	delete []heap;
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
	return size == 0;
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	return (size == capacity-1);
}

// PURPOSE: Prints the contents of the priority queue; format not specified
/*void PriorityQueue::print() const {
	for (int i = 1; i < size; i++)
	{
		cout << "Task Item " << i+1 << endl;
		cout << "Priority: " << heap[i]->priority << endl;
		cout << "Description: " << heap[i]->description << endl;
		cout << endl;
	}
}*/

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
	if (!empty())
		return (*(heap[1]));
	return TaskItem(-1, "N/A");
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
	if (size+1 == capacity)
		return false;
	if (size == 0) {
		heap[1] = new TaskItem(val);
		size++;
		return true;
	}
	else
	{
		int i = (size+1);
		heap[i] = new TaskItem(val);
		TaskItem* temp;
		while (i>1 && heap[i]->priority > heap[i/2]->priority)
		{
			temp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = temp;
			i /=2;
		}
		size++;
		return true;
	}
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {
	if (size == 0)
		return false;
	else if (size == 1)
	{
		delete heap[1];
		size--;
		return true;
	}
	
	int bottomRight = size;
	TaskItem* temp = heap[1];
	heap[1] = heap[bottomRight];
	heap[bottomRight] = temp;
	delete heap[bottomRight];
	size--;
	int i = 1;
	int left_child = 2*i; 
	int right_child = 2*i+1; 
	while (heap[left_child] != NULL || heap[right_child] != NULL)
	{
		if (heap[right_child] == NULL) {
			if (heap[left_child]->priority > heap[i]->priority)	 {
				temp = heap[left_child];
				heap[left_child] = heap[i];
				heap[i] = temp;
				i = left_child;
			}
		} 
		else {
			int max = heap[left_child]->priority > heap[right_child]->priority ? left_child : right_child; 
			if (heap[max]->priority > heap[i]->priority) {
				temp = heap[i]; 
				heap[i] = heap[max];
				heap[max] = temp; 
				i = max; 
			}
		}
		left_child = 2*i; 
		right_child = 2*i+1;
	}
	return true;
}
