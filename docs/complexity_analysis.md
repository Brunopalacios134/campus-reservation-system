# Complexity Analysis

### Reservation Insertion Complexity
O(1). A new node is created and linked directly to head in the active reservations linked list, in constant time regardless of how many reservations are already stored.

### Reservation Removal Complexity
O(n). The linked list must be traversed from head, comparing each node's reservation ID, until the matching reservation is found. In the worst case, this requires visiting every node in the list, making removal linear in the size of the list.

### Waiting-List Processing Complexity

- **Add to Waiting List:** O(1). A new node is created and linked directly to rear, in constant time regardless of how many students are already waiting.
- **Remove from Waiting List:** O(1). The front node is removed and its data returned in constant time, only accesses front and its next pointer, with a single constant-time check to update rear if the queue becomes empty.

Their time complexity remains constant regardless of how many students are waiting.

### Undo Cancellation Complexity
Cancellation History is implemented as a linked-list-based stack, where all operations act directly on the top pointer.

- **Store Cancellation:** O(1). A new node is created and linked to the current top in constant time, regardless of how many cancellations are already stored.
- **Restore Last Cancellation:** O(1). The top node is removed and its data returned in constant time, since the operation only accesses top and its next pointer.

Their time complexity does not grow with the number of stored cancellations.
