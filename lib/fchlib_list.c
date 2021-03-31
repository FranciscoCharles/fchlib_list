#include "fchlib_list.h"
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
static node_list create_node() {
    node_list new_node = (node_list)calloc(1, sizeof(struct node_list));
    if(new_node != NULL) {
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}
List list_delete(List self, void (*free_data)(void* data)) {
    if(self != NULL) {
        if(self->begin != NULL) {
            node_list tmp = NULL;
            while(self->begin != NULL) {
                tmp = self->begin;
                self->begin = self->begin->next;
                free_data(tmp->data);
                tmp->data = NULL;
                free(tmp);
                tmp = NULL;
            }
        }
        free(self);
        self = NULL;
    }
    return self;
}
List list_init(void) {
    List new_list = (List)calloc(1, sizeof(struct List));
    if(new_list != NULL) {
        new_list->begin = NULL;
        new_list->end = NULL;
    }
    return new_list;
}
List list_insert(List self,size_t index,void* data) {
    if(self == NULL) {
        self = list_init();
        self = list_push(self, data);
        if(self == NULL) {
            return self;
        }
    }
    node_list current = self->begin;
    node_list previous = NULL;
    node_list new_node = NULL;
    while((current != NULL) && (index > 0)) {
        previous = current;
        current = current->next;
        --index;
    }
    if(self->begin == NULL) {
        self = list_push(self, data);
    } else {
        new_node = create_node();
        if(new_node != NULL) {
            new_node->data = data;
            if(previous == NULL) {
                new_node->next = self->begin;
                self->begin->prev = new_node;
                self->begin = new_node;
            } else {
                new_node->next = current;
                new_node->prev = previous;
                previous->next = new_node;
                if(current != NULL) {
                    current->prev = new_node;
                } else {
                    self->end = new_node;
                }
            }
        }
    }
    return self;
}
bool list_is_empty(List self) {
    return (self == NULL) || (self->begin == NULL);
}
void* list_pop(List* self) {
    void* data = NULL;
    if((*self != NULL && (*self)->end!=NULL)) {
        node_list tmp = (*self)->end;
        (*self)->end = (*self)->end->prev;
        if((*self)->end!=NULL) {
            (*self)->end->next = NULL;
        } else {
            (*self)->begin = (*self)->end = NULL;
        }
        data = tmp->data;
        free(tmp);
        tmp = NULL;
    }
    return data;
}
void* list_pop_begin(List* self) {
    void* data = NULL;
    if((*self != NULL) && ((*self)->begin != NULL)) {
        node_list p = (*self)->begin;
        (*self)->begin = (*self)->begin->next;
        if((*self)->begin!=NULL) {
            (*self)->begin->prev = NULL;
        } else {
            (*self)->begin = (*self)->end = NULL;
        }
        data = p->data;
        free(p);
        p = NULL;
    }
    return data;
}
List list_push(List self, void* data) {
    if(self != NULL) {
        node_list new_node = create_node();
        if(new_node != NULL) {
            new_node->data = data;
            if(self->begin == NULL) {
                self->end = self->begin = new_node;
            } else {
                new_node->next = self->begin;
                self->begin->prev = new_node;
                self->begin = new_node;
            }
        }
    }
    return self;
}
List list_push_back(List self, void* data) {
    if(self != NULL) {
        node_list new_node = create_node();
        if(new_node != NULL) {
            new_node->data = data;
            if(self->end == NULL) {
                self->end = self->begin = new_node;
            } else {
                node_list tmp = self->end;
                new_node->prev = tmp;
                self->end = new_node;
                tmp->next = new_node;
            }
        }
    }
    return self;
}
void* list_remove(List* lista, size_t index) {
    node_list current = NULL;
    node_list previous = NULL;
    void* data = NULL;
    if((lista != NULL) && ((*lista)->begin != NULL)) {
        current = (*lista)->begin;

        while((current != NULL) && (index > 0)) {
            previous = current;
            current = current->next;
            --index;
        }
        if(previous == NULL) {

            data = current->data;
            if((*lista)->begin == (*lista)->end) {
                (*lista)->begin = (*lista)->end = (*lista)->begin->next;
            } else {
                (*lista)->begin = (*lista)->begin->next;
            }
            (*lista)->begin->prev = NULL;
        } else {

            if(current != NULL) {
                data = current->data;
                previous->next = current->next;
                if(current->next!=NULL) {
                    current->next->prev = previous;
                } else {
                    (*lista)->end = previous;
                }
            }
        }

        if(current != NULL) {
            free(current);
            current = NULL;
        }
    }
    return data;
}
size_t list_size(List self) {
    size_t size = 0;
    if(self != NULL) {
        node_list p = self->begin;
        while(p != NULL) {
            ++size;
            p = p->next;
        }
    }
    return size;
}
