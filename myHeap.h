#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

using namespace std;

const int MAX_SIZE = 100000; //the maximum amount of elements our heap should have.

template <typename Object>
class Heap
{
public:
   Heap(){
      elements = 0;
   };
   void insert(Object* item){// Add the object pointer item to the heap
	   if (elements >= MAX_SIZE){
		   cout << "Heap is full; can't insert "<< endl;
                     // FILL IN THE REST
			return;
	   }
      array[elements]=item;
      item->position = elements;
      upHeap(elements);
      elements++;
   };  	
   Object* remove_min(){
      if (elements ==0){
		   cout << "empty heap error, can't delete"<<endl;
	   }
      Object* temp = array[0];
      array[0] = array[elements - 1];
      elements--;
      if(elements > 0){
         array[0]->position = 0;
         downHeap(0);
      }
      temp->position = -1;

      return temp;
   };       // Remove the smallest element in the heap & restructure heap
   
   void decreaseKey(int pos, int val)// Decreases Key in pos to val
   {
      if (pos >= elements) {
         cout << "Out of range" << endl;
         return;
      }
      if(array[pos]->key <= val){
         cout << "New key is not smaller than current key" << endl;
         return;
      }

      array[pos]->key = val;
      upHeap(pos);  
   }; 
   

   bool IsEmpty() const {  return (elements <= 0);};
   bool IsFull() const {return (elements >=MAX_SIZE );};
   int count() const {return elements;};
   Object* value(int pos) const{ //return a pointer to an object in heap position
	   if (pos >= elements){
		   cout << "Out of range of heap " << pos << "elements " << elements << endl;
	   }
      return (array[pos]);
   };  
protected:
   Object* array[MAX_SIZE];
   int elements;       //  how many elements are in the heap
private:
   void downHeap(int pos){// starting with element in position pos, sift it down the heap 
   // until it is in final min-heap position
      Object* item = array[pos];
      int child;
      while (2*pos+1 < elements){
         child = 2*pos+1;
         if (child+1 < elements && array[child + 1]->key < array[child]->key){
            child++;
         }
         if (item->key > array[child]->key) {
         array[pos] = array[child];
         array[pos]->position = pos;
         pos = child;
         }
         else{
            break;
         }
      }
      array[pos]=item;
      item->position = pos;
   }; 

void upHeap(int new_pos){// starting with element in position int, sift it up the heap
   // until it is in final min-heap position
   Object* item = array[new_pos];
   int parent = (new_pos-1)/2;
   while (new_pos>0 && array[parent]->key > item->key){
      array[new_pos] = array[parent];
      array[new_pos]->position = new_pos;
      new_pos = parent;
      parent = (new_pos-1)/2;
      }
   array[new_pos] = item;
   item->position = new_pos;
   };   
};

#endif
