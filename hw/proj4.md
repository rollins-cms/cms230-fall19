# HashTable

## Description:

Implement a hash table using structures in C.

Your table must support initialization, insert, lookup, remove, and print operations
The keys and values in the table will both be of type `char*`. The keys will be null-terminated strings.

Use the starter code `hashtable.c` as a starting point. The `hashtable.h` header contains function prototypes and structure definitions.

This project will let you practice using memory allocation and structures to implement a non-trivial data structure. Along the way, you'll get to work with hash function (always an important topic) and arrays of pointers.

## Background:
Recall that a hash table is used to store key-value pairs and allows for average O(1) insert and lookup times if the load on the table is not too high.

A chained hash table consists of an array of "buckets". Each bucket contains a linked list of nodes that store the key-value pairs.  If you need a refresher on linked lists, (watch this video)[https://www.youtube.com/watch?v=VOpjAHCee7c].  It covers linked list concepts and implementation in C up to 14 minutes; after that, the end of the video is implementation in Java.

To insert into the table, calculate an integer from the key and use it to determine the bucket that should hold the new key-value pair, as in the following pseudo-C implementation:

```
void hashtableInsert(HashTable* h, char* key, char* value) {
   unsigned long int hashCode = hash(key);
   int b = hashCode % h->size;

   // Insert key-value pair into h->buckets[b]
}
```

You must implement functions to insert, lookup, and remove from the table.

### Rehashing:  
Recall that many hash table implementations, like Java's `HashMap`, track the load on the table as items are inserted and removed, where the load is defined to be the average number of items per bucket. If the load factor becomes too high---say, greater than .75 --- the implementation creates a new, larger table and rehashes all of the entries. You do not need to implement load-based rebalancing.

### Duplicates: 
The table can contain duplicate keys. A lookup or remove operation will always be satisfied by the first matching key that it encounters.

### Hash Functions: 
`hashtable.c` contains a `hash` function that implements Java's basic `String` hashing function. Don't modify `hash` -- if you do, your program will probably hash everything to different buckets and your outputs won't match the tests' expected outputs. 

## Testing and Grading:
As always, I grade the last submission you make.

There are a series of 12 testcases which test various functions of your code.  Ten of these are detailed in the comments in `main.c`.  `main.c` uses a very simplistic (and not particularly elegant) series of command line arguments to test specific functionality.  You can use these command line arguments to test your code and remove problems like seg faults. 

The remaining two testcases, labeled as "Memory Mangement" testcases, use the `valgrind` utlity to test your code for memory leaks.  The first requires that you correctly implement `hashTableInit` and `hashTableDestroy` in order to pass.  The last requires all functionality of your hashtable to be correctly implemented before it will pass.  Both of these testcases check to make sure that if you `malloc` memory, you later `free` it -- a requirement for programming in C.  You can run `valgrind` in your IDE workspace using the command:

```
valgrind --leak-check=full --error-exitcode=1 ./hash_table_test 1
```

The last argument of 1 runs the first memory mangement testcase.  Change this number to 11 to run the 2nd memory mangement testcase.

This is our first multi-file program.  Note that `hashtable.c` does not contain a main function. Therefore, it requires different options to compile.  Take a look at the `Makefile` provided, but you won't need to edit it.

## Tips and Hints:

* Start early!  This is perhaps the most complex (in terms of concepts) assignment you will have this semester.
* In this homework, you will almost certainly encounter the error "Segmentation fault (core dumped)''. This most often happens when you de-reference a NULL pointer. In other words, you try to use the `->` operator on a struct which has not been initialized, doesn't exist, or has already been `free`d.
* Use gdb to help you find errors like you did in Lab 3.
* I recommend you begin by implementing hashTableInit and hashTableDestroy as these functions are essentially opposites of each other.  You should pass testcases 1 and 2 after this.
* Start early and make use of office hours if you need them.
* Then work on implementing the `insert` and `lookup` functions.  These will require locating a bucket and traversing its associated linked list.  For insert, you will need to allocate memory and initialize a node.
* Removing is very similar to `lookup`, but you will need to be careful of your pointer management.  After implementing insert, lookup, and remove, you will be passing about half of the testcases.
* Start early.
