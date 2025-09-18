"""The positioning in this file does not starts with 0"""

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.prev = None
class DoublyLinkedList:
    def __init__(self):
        self.Head = None
        self.Tail = None
    # Display
    def display(self):
        temp = self.Head
        while(temp is not None):
            print(temp.data)
            temp = temp.next

    # Insertion
    def insertion_head(self,data):
        newNode = Node(data)
        if self.isEmpty():
            self.Tail = newNode
        else :
            self.Head.prev = newNode
        newNode.next = self.Head
        self.Head = newNode       
        
    def insertion_tail(self,data):
        newNode = Node(data)
        newNode.next = None
        self.Tail.next = newNode
        newNode.prev = self.Tail
        self.Tail = newNode

    def insertion_atPos(self,data,pos):
        if (pos == 0) : self.insertion_head(data)
        else:
            count = 0
            temp = self.Head
            while (count < pos-1 and temp != None):
                temp = temp.next
                count += 1
            if (temp == None):
                print("Index out of bounds!")
                return temp
            newNode = Node(data)
            newNode.next = temp.next
            newNode.prev = temp
            temp.next.prev = newNode
            temp.next = newNode

    # Deletion
    def deletion_head(self):
        if (self.Head is None):
            print("Underflow!")
        else:
            temp = self.Head
            self.Head = self.Head.next
            self.Head.prev = None
            temp.next = None
            return temp
            
    def deletion_tail(self):
        if (self.Head is None):
            print("Underflow!")
        else:
            temp = self.Tail
            self.Tail = self.Tail.prev
            self.Tail.next = None
            temp.prev = None
            return temp

    def deletion_atPos(self,pos):
        if (pos==0):
            self.deletion_head()
            return
        count = 0
        temp = self.Head
        while temp is not None and count<pos-1:
            temp = temp.next
            count += 1
        if (temp is None or temp.next is None):
            print("Index out of bounds!")
            return
        deleted = temp
        temp.prev.next = temp.next
        temp.next.prev = temp.prev
        return deleted

    def isEmpty(self):
        return self.Head is None



def main():
    list1 = DoublyLinkedList()
    
    print("Inserting 10 at Head")
    list1.insertion_head(10)
    print("Inserting 0 at Head")
    list1.insertion_head(0)
    print("\nPrint List : ")
    list1.display()

    print("\nInserting 100 at Tail")
    list1.insertion_tail(100)
    print("Inserting 1000 at Tail")
    list1.insertion_tail(1000)
    print("Insertion of 10 at positon 2 ")
    list1.insertion_atPos(10,2)
    print("\nPrint List : ")
    list1.display()
    
    print("\nDelete Head")
    list1.deletion_head()
    print("Delete Tail")
    list1.deletion_tail()
    print("\nDeletion at position 2")
    list1.deletion_atPos(2)
    print("\nPrint List : ")
    list1.display()

    print("\nPrint List : ")
    list1.display()


if __name__=='__main__':
    main()


    



        
            


            
