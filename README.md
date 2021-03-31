<p align="center">
  <img src="logo.png" width="400" height="180">  
</p>

<p align="center">
  Welcome to the <b>README</b> of the <b>fchlib_list</b> library.
</p>

# Description  

**fchlib_list** é uma biblioteca escrita em C responsavel por manipular uma estrutura de dados do tipo lista duplamente encadeada. A biblioteca dispoe de funções variadas de inserção e remoção de dados.

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

<!--

#define lst_push(self, data) self=list_push(self,data)
#define lst_push_back(self, data) self=list_push_back(self,data)
#define lst_pop(self) list_pop(&self)
#define lst_pop_begin(self) list_pop_begin(&self)
#define lst_remove(self, index) list_remove(&self,index)
#define lst_delete(self, free_data) self=list_delete(self,free_data)
#define lst_insert(self, index, data) self=list_insert(self,index,data)
--->

# **<a name=list_delete>list_delete</a>**  <h6>[back to indice](#index)</h6>
Esta função libera a memoria alocada por uma estrutura do tipo lista.

- ## function prototype :  
   
```c
List list_delete(List self,void (*free_data)(void* data));
```

- ## parameters:
  - self `(List)`: lista a ser liberada.
  - free_data `function`: um ponteiro para uma função adequada de liberação de memoria para o tipo de dado armazenado em `self`.
- ## returns:
  - `(NULL)`: esta função retorna `NULL`.

- ## example of use:
```c
list = lits_delete(list, free_data);
```
# **<a name=list_init>list_init</a>**  <h6>[back to indice](#index)</h6>
Esta função é responsavel por alocar e inicializar um objeto `(List)`.

- ## function prototype :  
   
```c
List list_init(void);
```

- ## parameters:
  `None`
- ## returns:
  - `(List)`: retorna um ponteiro para um `(List)` recem alocado ou `NULL` em caso de falha.

- ## example of use:
```c
List list = list_init();
```
# **<a name=list_is_empty>list_is_empty</a>**  <h6>[back to indice](#index)</h6>
Esta função verifica se um objeto `(List)` é vazio.

- ## function prototype :  
   
```c
bool list_is_empty(List self);
```

- ## parameters:
  - self `(List)`: lista a ser verificada.

- ## returns:
  - `(bool)`: return `true` se `self` é `NULL` ou se `self->begin` é `NULL`.

- ## example of use:
```c
bool is_empty = list_is_empty(list);
```
# **<a name=list_insert>list_insert</a>**  <h6>[back to indice](#index)</h6>
Esta função insere um dado em alguma posicao de uma lista.

- ## function prototype :  
   
```c
List list_insert(List self, size_t index, void* data);
```

- ## parameters:
  - self `(List)`: lista de origem.
  - index `(size_t)`: posição a ser inserida.
  - data `(void*)`: o dado a ser inserido.

- ## returns:
  - `(List)`: retorna a mesma referencia a `self`.

- ## example of use:
```c
int *a=NULL, *b=NULL, *c=NULL;

a = (int)malloc(sizeof int);
b = (int)malloc(sizeof int);
c = (int)malloc(sizeof int);

*a = 9;
*b = 10;
*c = 11;

list = list_insert(list, 0, a);
list = list_insert(list, 0, b);
list = list_insert(list, 0, c);

/*list contains [ 11, 10, 9]*/

a = b = c = NULL;
```
# **<a name=list_pop>list_pop</a>**  <h6>[back to indice](#index)</h6>
Esta função remove o ultimo elemento de uma lista.

- ## function prototype :  
   
```c
void* list_pop(List* self);
```

- ## parameters:
  - self `(List*)`: ponteiro para o endereço da lista de origem.

- ## returns:
  - `(void*)`: libera o ultimo nó da lista e retorna o ponteiro para o dado armazenado. Em caso de falha ele retorna `NULL`.

- ## note:
  Esta função não libera o dado retornado, lembre-se de libera-lo manualmente.

- ## example of use:
```c
/*imagine uma lista com [1, 2, 3]*/
int *data = list_pop( &list );
printf("number %d\n", *data); /*print "number 3"*/
```
# **<a name=list_pop_begin>list_pop_begin</a>**  <h6>[back to indice](#index)</h6>
Esta função remove o primeiro dado presente em uma lista.

- ## function prototype :  
   
```c
void* list_pop_begin(List* self);
```

- ## parameters:
  - self `(List*)`: ponteiro para o endereço da lista de origem.

- ## returns:
  - `(void*)`: libera o primeiro nó da lista e retorna o ponteiro para o dado armazenado. Em caso de falha ele retorna `NULL`.

- ## note:
  Esta função não libera o dado retornado, lembre-se de libera-lo manualmente.

- ## example of use:
```c
/*imagine uma lista com [1, 2, 3]*/
int *data = list_pop_begin( &list );
printf("number %d\n", *data); /*print "number 1"*/
```
# **<a name=list_push>list_push</a>**  <h6>[back to indice](#index)</h6>
Esta função insere um dado no inicio de uma lista.

- ## function prototype :  
   
```c
List list_push(List self, void* data);
```
- ## parameters:
  - self `(List)`: lista de origem.
  - dado `(void*)`: dado a ser inserido.

- ## returns:
  - `(List)` : retorna a mesma referencia a `self`.

- ## example of use:
```c
/*imagine uma lista com [1, 2, 3]*/
int *data = (int)malloc(sizeof int);
*data = 4;
list = list_push( list, data);
data = NULL;
/*list contains [4, 1, 2, 3]*/
```
# **<a name=list_push_back>list_push_back</a>**  <h6>[back to indice](#index)</h6>
Esta função insere um dado ao final de uma lista.

- ## function prototype :  
   
```c
List list_push_back(List self, void* data);
```

- ## parameters:
  - self `(List)`: lista de origem.
  - dado `(void*)`: dado a ser inserido.

- ## returns:
  - `(List)` : retorna a mesma referencia a `self`.

- ## example of use:
```c
/*imagine uma lista com [1, 2, 3]*/
int *data = (int)malloc(sizeof int);
*data = 4;
list = list_push_back( list, data);
data = NULL;
/*list contains [1, 2, 3, 4]*/
```
# **<a name=list_remove>list_remove</a>**  <h6>[back to indice](#index)</h6>
Esta função remove um dado em uma determinada posicao da lista.

- ## function prototype :  
   
```c
void* list_remove(List* self, size_t index);
```

- ## parameters:
  - self `(List*)`: ponteiro para o endereço da lista de origem.
  - index `(size_t)`: posição do elemento a ser removido.

- ## returns:
  - `(void*)`: libera o nó da lista e retorna o ponteiro para o dado armazenado. Em caso de falha ele retorna `NULL`.

- ## note:
  Esta função não libera o dado retornado, lembre-se de libera-lo manualmente.

- ## example of use:
```c
/*imagine uma lista com [1, 2, 3]*/
int *data = list_remove( &list, 1);/*remove o elemento 2*/
free(data);
data = NULL;
```
# **<a name=list_size>list_size</a>**  <h6>[back to indice](#index)</h6>
Esta função retorna o numero de elementos de uma lista.

- ## function prototype :  
   
```c
size_t list_size(List self);
```

- ## parameters:
  - self `(List)`: lista de origem.

- ## returns:
  - `(size_t)` : retorna o tamanho da lista ou 0 caso `self` ou `self->begin`sejam `NULL`.
  
- ## example of use:
```c
/*imagine uma lista com [1, 2, 3, 4]*/
size_t size = list_size(list);/*retorna 4*/
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