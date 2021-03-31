<p align="center">
  <img src="logo.png" width="400" height="180">  
</p>

<p align="center">
  Welcome to the <b>README</b> of the <b>fchlib_list</b> library.
</p>

# Description

**fchlib_list** is a library written in C responsible for handling a double-linked list data structure. The library has a variety of data insertion and removal functions. The List structure offers support for generic types through pointer (void*).

# <a name=index>Table of contents</a>
 
- [**list_delete**](#list_delete)
- [**list_init**](#list_init)
- [**list_insert**](#list_insert)
- [**list_is_empty**](#list_is_empty)
- [**list_pop**](#list_pop)
- [**list_pop_begin**](#list_pop_begin)
- [**list_push**](#list_push)
- [**list_push_back**](#list_push_back)
- [**list_remove**](#list_remove)
- [**list_size**](#list_size)
- [**Versions**](#version)

# **<a name=list_delete>list_delete</a>**  <h6>[back to indice](#index)</h6>
This function frees the memory allocated by a list type structure.

- ## function prototype :  
   
```c
List list_delete(List self,void (*free_data)(void* data));
```

- ## parameters:
  - self `(List)`: source list.
  - free_data `function`: a pointer to an appropriate memory release function for the type of data stored in `self`.
- ## returns:
  - `(NULL)`: this function returns `NULL`.

- ## example of use:
```c
list = lits_delete(list, free_data);
```
or using the **lst_delete** macro:
```c
lst_delete(list, free_data);
```

# **<a name=list_init>list_init</a>**  <h6>[back to indice](#index)</h6>
This function is responsible for allocating and initializing a `(List)` object.

- ## function prototype :  
   
```c
List list_init(void);
```

- ## parameters:
  `None`
- ## returns:
  - `(List)`: returns a pointer to a newly allocated `(List)` or `NULL` in case of failure.

- ## example of use:
```c
List list = list_init();
```
# **<a name=list_insert>list_insert</a>**  <h6>[back to indice](#index)</h6>
This function inserts data into a list at a given position.

- ## function prototype :  
   
```c
List list_insert(List self, size_t index, void* data);
```

- ## parameters:
  - self `(List)`: source list.
  - index `(size_t)`: position to be inserted.
  - data `(void*)`: the data to be inserted.

- ## returns:
  - `(List)`: returns the same reference to `self`.

- ## example of use:
```c
int *a=NULL, *b=NULL, *c=NULL;

a = (int)malloc(sizeof (int));
b = (int)malloc(sizeof (int));
c = (int)malloc(sizeof (int));

*a = 9;
*b = 10;
*c = 11;

list = list_insert(list, 0, a);
list = list_insert(list, 0, b);
list = list_insert(list, 0, c);

/*result: the list contains [11, 10, 9]*/

a = b = c = NULL;
```
or using the **lst_insert** macro:
```c
int *a=NULL, *b=NULL, *c=NULL;

a = (int)malloc(sizeof (int));
b = (int)malloc(sizeof (int));
c = (int)malloc(sizeof (int));

*a = 9;
*b = 10;
*c = 11;

lst_insert(list, 0, a);
lst_insert(list, 0, b);
lst_insert(list, 0, c);

/*result: the list contains [11, 10, 9]*/

a = b = c = NULL;
```
# **<a name=list_is_empty>list_is_empty</a>**  <h6>[back to indice](#index)</h6>
This function checks whether an `(List)` object is empty.

- ## function prototype :  
   
```c
bool list_is_empty(List self);
```

- ## parameters:
  - self `(List)`: list to be checked.

- ## returns:
  - `(bool)`: returns `true` if` self` is `NULL` or if` self-> begin` is `NULL`.

- ## example of use:
```c
bool is_empty = list_is_empty(list);
```

# **<a name=list_pop>list_pop</a>**  <h6>[back to indice](#index)</h6>
This function removes the last element from a list.

- ## function prototype :  
   
```c
void* list_pop(List* self);
```

- ## parameters:
  - self `(List*)`: pointer to the list address.

- ## returns:
  - `(void*)`: releases the last node in the list and returns the pointer to the stored data. In case of failure, returns `NULL`.

- ## note:
  This function does not release the returned data, remember to release them manually.

- ## example of use:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = list_pop( &list );
printf("number %d\n", *data); /*print "number 3"*/
```
or using the **lst_pop**  macro:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = lst_pop( list );
printf("number %d\n", *data); /*print "number 3"*/
```
# **<a name=list_pop_begin>list_pop_begin</a>**  <h6>[back to indice](#index)</h6>
This function removes the first element from a list.

- ## function prototype :  
   
```c
void* list_pop_begin(List* self);
```

- ## parameters:
  - self `(List*)`: pointer to the list address.

- ## returns:
- `(void*)`: releases the first node in the list and returns the pointer to the stored data. In case of failure, return `NULL`.

- ## note:
  This function does not release the returned data, remember to release them manually.

- ## example of use:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = list_pop_begin( &list );
printf("number %d\n", *data); /*print "number 1"*/
```
or using the **lst_pop_begin** macro:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = lst_pop_begin( list );
printf("number %d\n", *data); /*print "number 1"*/
```
# **<a name=list_push>list_push</a>**  <h6>[back to indice](#index)</h6>
This function inserts an element at the beginning of a list.

- ## function prototype :  
   
```c
List list_push(List self, void* data);
```
- ## parameters:
  - self `(List)`: source list.
  - data `(void*)`: data to be inserted.

- ## returns:
  - `(List)`: returns the same reference to `self`.

- ## example of use:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = (int)malloc(sizeof (int));
*data = 4;
list = list_push( list, data);
data = NULL;
/*list contains [4, 1, 2, 3]*/
```
or using the **lst_push** macro:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = (int)malloc(sizeof (int));
*data = 4;
lst_push( list, data);
data = NULL;
/*list contains [4, 1, 2, 3]*/
```
# **<a name=list_push_back>list_push_back</a>**  <h6>[back to indice](#index)</h6>
This function inserts an element at the end of a list.

- ## function prototype :  
   
```c
List list_push_back(List self, void* data);
```
- ## parameters:
  - self `(List)`: source list.
  - data `(void*)`: data to be inserted.

- ## returns:
  - `(List)`: returns the same reference to `self`.

- ## example of use:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = (int)malloc(sizeof (int));
*data = 4;
list = list_push_back( list, data);
data = NULL;
/*result: list contains [1, 2, 3, 4]*/
```
or using the **lst_push_back** macro:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = (int)malloc(sizeof (int));
*data = 4;
lst_push_back( list, data);
data = NULL;
/*result: list contains [1, 2, 3, 4]*/
```
# **<a name=list_remove>list_remove</a>**  <h6>[back to indice](#index)</h6>
This function removes an element at a certain position in the list.

- ## function prototype :  
   
```c
void* list_remove(List* self, size_t index);
```

- ## parameters:
  - self `(List *)`: pointer to the address of the list.
  - index `(size_t)`: position of the element to be removed.

- ## returns:
  - `(void *)`: releases the list node and returns the pointer to the stored data. In case of failure it returns `NULL`.

- ## note:
  This function does not release the returned data, remember to release them manually.

- ## example of use:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = list_remove( &list, 1);/*removes element 2*/
free(data);
data = NULL;
```
or using the **lst_remove** macro:
```c
List list = ... /*suppose a list with [1, 2, 3]*/
int *data = list_remove( list, 1);/*removes element 2*/
free(data);
data = NULL;
```
# **<a name=list_size>list_size</a>**  <h6>[back to indice](#index)</h6>
This function returns the number of elements in a list.

- ## function prototype :  
   
```c
size_t list_size(List self);
```

- ## parameters:
  - self `(List)`: source list.

- ## returns:
  - `(size_t)`: returns the size of the list or 0 if `self` or` self-> begin` are `NULL`.
  
- ## example of use:
```c
List list = ... /*suppose a list with [1, 2, 3, 4]*/
size_t size = list_size(list);/*return 4*/
```
# **<a name=version>Version</a>**  <h6>[back to indice](#index)</h6>

- current version:
  <h5><b>1.0.02022019</b></h5>

- previous versions:
  ~~<h5>1.0.01022019<h5>~~
---

<p align="center">
    Copyright © 2019-2021 <b>FranciscoCharles</b>
</p>