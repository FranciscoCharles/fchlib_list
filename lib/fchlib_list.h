#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
MIT License

Copyright (c) 2019-2021 FranciscoCharles

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

typedef struct List* List;
typedef struct node_list* node_list;

struct node_list {
    void* data;
    node_list prev;
    node_list next;
};
struct List {
    node_list begin;
    node_list end;
};

/*shortcut macro*/
#define lst_begin(self) (((self)!=NULL)?(self)->begin:NULL)
#define lst_delete(self, free_data) (self)=list_delete((self),free_data)
#define lst_end(self) (((self)!=NULL)?(self)->end:NULL)
#define lst_insert(self, index, data) (self)=list_insert((self),index,data)
#define lst_push(self, data) (self)=list_push((self),data)
#define lst_push_back(self, data) (self)=list_push_back((self),data)
#define lst_pop(self) list_pop(&(self))
#define lst_pop_begin(self) list_pop_begin(&(self))
#define lst_remove(self, index) list_remove(&(self),index)

bool list_is_empty(List self);
size_t list_size(List self);
List list_init(void);
List list_delete(List self,void (*free_data)(void* data));
List list_insert(List self, size_t index, void* data);
List list_push(List self, void* data);
List list_push_back(List self, void* data);
void* list_pop(List* self);
void* list_pop_begin(List* self);
void* list_remove(List* self, size_t index);

#endif /* _LIST_H_ */
