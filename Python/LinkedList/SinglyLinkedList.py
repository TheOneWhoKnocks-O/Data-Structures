class Node :
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.Head = None

    # Display
    def display(self):
        temp = self.Head
        while(temp is not None):
            print(temp.data)
            temp = temp.next

    # Insertion
    def insertion_head(self,data):
        newNode = Node(data)
        if self.Head != None:
            newNode.next = self.Head
        self.Head = newNode

    def insertion_tail(self,data):
        if (self.Head is None): self.insertion_head(data)
        else:
            temp = self.Head
            while(temp.next != None):
                temp = temp.next
            temp.next = Node(data)

    def insertion_atPos(self,data,pos):
        if (pos == 0): self.insertion_head(data)
        else:
            count = 0
            temp = self.Head
            while(count < pos-1 and temp != None):
                temp = temp.next
                count += 1
            if (temp == None) :
                print("Index out of bounds!")
                return temp
            newNode = Node(data)
            newNode.next = temp.next
            temp.next = newNode
                
    # Deletion
    def deletion_head(self):
        if self.Head == None:
            print("Underflow!")
        else:
            temp = self.Head
            self.Head = self.Head.next
            temp.next = None
            return temp
    def deletion_tail(self):
        if self.Head is None:
            print("Underflow!")
            return
        temp = self.Head
        if self.Head.next is None:
            self.Head = None
            return temp
        while temp.next.next is not None:
            temp = temp.next
        deleted = temp.next
        temp.next = None
        return deleted    

    def deletion_atPos(self, pos):
        if self.Head is None:
            print("Underflow!")
            return
        if pos == 0:
            deleted = self.deletion_head()
            return
        count = 0
        temp = self.Head
        while temp is not None and count < pos - 1:
            temp = temp.next
            count += 1
        if temp is None or temp.next is None:
            print("Index out of bounds!")
            return
        deleted = temp.next
        temp.next = temp.next.next
        return deleted

    def isEmpty(self):
        return self.Head is None

    def reverse(self):
        prev = None
        current = self.Head

        while current:
            # Store the current node's next node.
            next_node = current.next
            # Make the current node's next point backwards
            current.next = prev
            # Make the previous node be the current node
            prev = current
            # Make the current node the next node (to progress iteration)
            current = next_node
        # Return prev in order to put the head at the end
        self.Head = prev

def main():
    list = LinkedList()
    print("Inserting 10 at Head")
    list.insertion_head(10)
    print("Inserting 0 at Head")
    list.insertion_head(0)
    print("\nPrint List : ")
    list.display()

    print("\nInserting 100 at Tail")
    list.insertion_tail(100)
    print("Inserting 1000 at Tail")
    list.insertion_tail(1000)
    print("Insertion of 10 at positon 2 ")
    list.insertion_atPos(10,2)
    print("\nPrint List : ")
    list.display()
    
    print("\nDelete Head")
    list.deletion_head()
    print("Delete Tail")
    list.deletion_tail()
    print("\nDeletion at position 2")
    list.deletion_atPos(2)
    print("\nPrint List : ")
    list.display()

    print("\nReverse Linked List")
    list.reverse()
    print("\nPrint List : ")
    list.display()


if __name__=='__main__':
    main()
