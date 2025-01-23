# LINKED-LIST-IMPLEMENTATION_TASK-2

Name : NEHA DE

Company: CODETECH IT SOLUTIONS

ID: CTO8MCG

Domain: C programming

Duration: January 15th, 2025 to February 15th, 2025

Mentor: Neela Santhosh Kumar

LINKED-LIST-IMPLEMENTATION

Output of the code
![Task_2](https://github.com/user-attachments/assets/ca756de5-ea14-49b8-8358-1e600ec5d381)

Project Overview

A linked list is a linear data structure where elements, called nodes, are connected via pointers. Each node contains two parts: data (the value) and a pointer (reference) to the next node in the sequence. The last node's pointer is set to NULL, indicating the end of the list.

Types of Linked Lists:
1. Singly Linked List: Each node points to the next node. Traversal is one-directional.
2. Doubly Linked List: Each node has pointers to both the previous and next nodes, allowing bidirectional traversal.
3. Circular Linked List: The last node points back to the first node, forming a loop.

Key Operations:
1. Insertion:
At Beginning: Create a new node and point it to the current head.
At End: Traverse to the last node and update its pointer to the new node.
At Position: Traverse to the desired position and adjust pointers to include the new node.
2. Deletion:
From Beginning: Update the head pointer to the next node.
From End: Traverse to the second-last node and set its pointer to NULL.
From Position: Adjust pointers to skip the node at the specified position.
3. Traversal: Start from the head and follow the pointers to visit each node.
4. Search: Traverse the list to locate a node with the desired value.

Advantages:
Dynamic size.
Efficient insertion and deletion (no shifting of elements).

Disadvantages:
Higher memory usage (extra pointer per node).
Sequential access (no direct indexing).

Applications:
Implementation of stacks, queues, and graphs.
Managing memory (e.g., free lists in OS).
