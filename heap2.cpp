#include<iostream>
		using namespace std;



		class BinaryHeap
		{
		    public:
		    int* arr;//pointer to the beginning of the array which implements the binary heap
		    int maxSize;//stores the maximum size of the array
		    int currSize;//stores the current size of the array


		    BinaryHeap(int maxSize)
		    {
			arr=new int[maxSize];//array with the passed size is declared
			this->maxSize=maxSize;//date memeber maxSize is initialized
			currSize=0;//current size is inilialized to zero
		    }


	
		    void swap(int a,int b)//function to swap the elements at two array indice
		    {
			arr[a]=arr[a]+arr[b];
			arr[b]=arr[a]-arr[b];
			arr[a]=arr[a]-arr[b];
		    }
		    int getParent(int i){return (i-1)/2;  }   
		    int getLeft(int i){return (i*2)+1;}      
		    int getRight(int i){return (i*2)+2;}
		    int getMin(){return arr[0];}  

            //insert  

		    void insert(int num)
		    {
            //if array index is not out of bounds
			if(currSize==maxSize)
            //else heap overflows
			cout<<"Heap Overflow"<<endl;
			else
			{
                //the value is added into the next element at the end
			    arr[currSize++]=num;
			    int i=currSize-1;
                //loop to check the hierarchy of the heap elements
			    while(i>0&&arr[i]<arr[getParent(i)])
			    {
                //if the hierarchy is broken then the elemnts are swapped    
				swap(i,getParent(i));
                //the heirarchy is checker for the parent of the current node till the root is reached
				i=getParent(i);
			    }
			}
		    }
			  
		    void display(int i,int space)
		    {
                //if the end of the subtree has not been reached
			if(i<currSize)
			{
                //the right subtree is displayed with an increased tab space
			    display(getRight(i),++space);
                //a new line to print the current node value
			    cout<<endl;

                //for loop to print the correct number
                for(int i=1;i<space;i++)
			    cout<<"\t";
                //the value at the root of the current subtree is displayed
                 cout<<arr[i]<<endl;
		
			    display(getLeft(i),space);
		
			}
		    }


		    //function to return the minimum of the elements in the heap
            int extractMin()
		    {
            //if the heap is empty    
			if(currSize==0)
			return -9999;
			else if(currSize==1)
			return arr[currSize--];
			else
			{
			    //the minimum of the heap is stored
                int min=getMin();
                //the last element of the heap is copied to the root
			    arr[0]=arr[--currSize];
                //minHeapify moves the root value to its correct position in the heap
			    minHeapify(0);
                //the deleted element is returned
			    return min;
			}        
		    }

		    //function to reduce the value of the node to be deleted to the minimum in the tree
            void decreaseKey(int i)
		    {
            //value of the node to be deletd is decreased    
			arr[i]=getMin()-1;
			while(i>0&&arr[i]<arr[getParent(i)])
			{
			    swap(i,getParent(i));
			    i=getParent(i);
			}
		    }


            //function to delete the element at index i
            void deleteAt(int i)
		    {
			decreaseKey(i);
            //extracts the minimum from the tree
			i=extractMin();
		    }



		    //function to check the realtion of the parent with the child
            void minHeapify(int i)
		    {
			int least=i;
            //the relation of the left child with the parent is checked
			if(getLeft(i)<currSize&&arr[getLeft(i)]<arr[least])
			least=getLeft(i);
            //the relation of the right child with the parent is checked
			if(getRight(i)<currSize&&arr[getRight(i)]<arr[least])
			least=getRight(i); 
            //if the rule is not satisfied   
			if(least!=i)
			{
			    //they are swapped
                swap(i,least);
                //the rule is checked for the child of the current node
			    minHeapify(least);
			}
		    }
		};
		
		int main(){
		    BinaryHeap bh1(20);
		    for(int i=10;i>0;i--)
		    bh1.insert(i);
		    bh1.display(0,0);
		    int i=bh1.extractMin();
		    cout<<i<<endl;
		    bh1.display(0,0);
		    bh1.deleteAt(5);
		    bh1.display(0,0);
		    cout<<endl;
}