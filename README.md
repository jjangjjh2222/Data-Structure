# 자료구조
## 1. Stack
### C언어를 사용하여 Stack operation을 Array와 Linked List 2가지 방법으로 구현합니다.

<br>

### 기초 Operation
- is_empty() : 스택이 비어있는지 True/False 반환
- is_full() : 스택이 가득찼는지 True/False 반환
- push() : 스택에 원소 삽입
- pop() : 스택의 최상위 원소(top) 삭제하고 반환

<br>

### 심화 Operation
- get_stack_size() : 현재 스택 원소 개수 반환
- get_top() : 스택 최상위 원소 반환
- print_stack() : 스택의 최상위 원소부터 순서대로 원소를 출력

<br>

## 2. Queue
### C언어를 사용하여 Queue의 기본 operation을 Array와 Linked List 2가지 방법으로 구현합니다.

<br>

### Queue 기초 Operation

- is_empty() : Queue가 비어 있는지 True/False 반환
- is_full() : Queue가 가득 찼는지 True/False 반환
- enqueue() : EnQueue    * 예외처리 : enqueue 과정에 문제가 생긴다면 -1 반환, 성공 시 0 반환
- dequeue() : Dequeue    * 예외처리 : dequeue 과정에 문제가 생긴다면 -1 반환, 성공 시 Dequeue 값 반환
- Stack/Queue 심화, Double-Ended Queue (Deque) 구현

<br>

### Double-Ended Queue (Deque)
- stack : Last-Input Fist-Output (LIFO)
- Queue : First-Input First-Output (FIFO)
- Deque : Stack, Queue 두 기능을 모두 가지고 있음, 양 방향으로 입출력이 가능

<img src = "https://user-images.githubusercontent.com/88773219/179368637-86e7819a-9d58-4b8f-87fe-9cdd68c46edd.png" width="90%"></img>

<br>

### Deque Operation - Linked List 구현
- is_empty() : Deque가 비어있는지 True/False 반환
- is_full() : Deque가 가득 찼는지 True/False 반환
- addfront(), addrear()
- delfront(), delrear() <br>

*에외처리 : 입출력 과정에 문제가 있다면 -1 반환, 성공 시 0 or 출력 값 반환

<br>

## 3. LinkedList
### C언어를 사용하여 Doubly Linked List의 기본 operation을 활용해 간단한 주소록을 구현합니다.

<br>

### 기초 Operation
- is_empty() / is_full() : Queue가 empty/full인지 True/False 반환
- insert_head() / insert_tail(), delete_head() / delete_tail() 
<br>
*예외처리 : Insert, Delete 과정에 문제가 생긴다면 -1 반환, 성공 시 0 반환

<img src="https://user-images.githubusercontent.com/88773219/179369241-f834757a-d610-4ee9-a1ee-59fd4e8b3b35.png" width="90%"></img>

<br>

### 심화 Operation
- search_name(id) : 학번으로 리스트에서 해당 학생 노드를 찾고 이름을 출력 -> 성공 0 / 실패 -1 출력
- search_id(name) : 이름으로 리스트에서 해당 학생 노드를 찾고 학번을 출력 -> 성공 0 / 실패 -1 출력
- 특이사항 : 학번은 고유 번호로 학생마다 다르나, 이름은 같은 사람이 있을 수 있습니다. 따라서 find_id의 경우에는 검색한 이름과 동일한 모든 학생들을 출력합니다.

<br>


## 4. Tree
### C언어를 사용하여 Binary Tree의 기본 Operation과 Binary Tree Traversals를 구현한다.

<br>

### Binary Tree 기초 Operation
- BinaryTree* bt_create(int x) : data가 x이고 subtree가 비어있는 노드를 생성하고 반환합니다.
- bool bt_is_empty(BinaryTree* bt) : 노드의 subtree가 비었는지 확인합니다. (비었으면 True 반환)
- BinaryTree* bt_make(BinaryTree* root, BinaryTree* bt1, BinaryTree* bt2) : root의 leftchild가 bt1, right child가 bt2로 설정하고, root를 반환합니다.

<br>

### Binary Tree Traversals
- void bt_print_preorder(BinaryTree* bt)
- void bt_print_postorder(BinaryTree* bt)
- void bt_print_inorder(BinaryTree* bt)
## 5. Sorting
