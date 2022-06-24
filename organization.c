#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int id, char* name, int salary) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = id;
    ptr->emp_salary = salary;
    ptr->emp_name = strdup(name);
    // strdup() creates a copy of the string or char pointer and stores it in the new char pointer of the employee
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int id, salary;
    char name[100];
    scanf("%d", &id);
    if(id == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present

    scanf("%s %d", name, &salary);
    struct Employee* par = create_employee(id, name, salary);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}

// The following function 
void print_company_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d %s %d ", ceo->emp_id, ceo->emp_name, ceo->emp_salary);
    print_company_helper(ceo->subordinate_1);
    print_company_helper(ceo->subordinate_2);
    return;
}

void print_company(struct Employee* ceo) {
    print_company_helper(ceo);
    printf("\n");
    return;
} 

// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------
// ------------------------------------------------------ PYTHON LIST 2 -----------------------------------------------
struct Node{
    struct Employee* emp;
    struct Employee* boss;
    int level;
    struct Node* next;
};

struct Node* create_node(struct Employee* Emp, struct Employee* Boss, int level) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->emp = Emp;
    ptr->boss = Boss;
    ptr->level = level;
    return ptr;
}

void delete_node(struct Node* ptr) {
    free(ptr);
}

struct Node* PythonListHead = NULL;

//Adds in front
void push(struct Employee* Emp, struct Employee* Boss, int level) {
    struct Node* add = create_node(Emp,Boss,level);
    if (PythonListHead == NULL)
        PythonListHead = add;
    else{
        struct Node* store = PythonListHead;
        PythonListHead = add;
        PythonListHead->next = store;
    }
}

void clear() {
    struct Node* cur = PythonListHead;
    PythonListHead = NULL;
    while(cur) {
        struct Node* next_node = cur->next;
        delete_node(cur);
        cur = next_node;
    }
}
// ------------------------------------------------- PYTHON LIST 2 ENDS -----------------------------------------------
//-----------------------------------------------------PYTHON LIST 1--------------------------------------------------

struct Node_1* PythonListHead_1 = NULL;

struct Node_1
{
    int data;
    int lvl;
    struct Node_1* next;
};

// create a node with data as x
struct Node_1* create_node_1(int x, int y) {
    struct Node_1* ptr = malloc(sizeof(struct Node_1));
    ptr->next = NULL;
    ptr->data = x;
    ptr->lvl = y;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node_1(struct Node_1* ptr) {
    free(ptr);
}

void append(int x, int lvl) {
    struct Node_1* add = create_node_1(x, lvl);
    if (PythonListHead_1 == NULL)
        PythonListHead_1 = add;
    else{
        struct Node_1* store = PythonListHead_1;
        PythonListHead_1 = add;
        PythonListHead_1->next = store;
    }
}

void clear_1() {
    struct Node_1* cur = PythonListHead_1;
    PythonListHead_1 = NULL;
    while(cur) {
        struct Node_1* next_node = cur->next;
        delete_node_1(cur);
        cur = next_node;
    }
}

//removes the first instnce with given data
int print_emp_id_max_lvl(int lvl){
    struct Node_1* cur = PythonListHead_1;
    int max_level = 0;
    while(cur){
        if(cur->lvl == lvl)
            printf("%d ", cur->data);
        if(cur->lvl > max_level)
            max_level = cur->lvl;
        cur = cur->next;
    }
    return max_level;
}

//--------------------------------------------------PYTHON LIST 1 ENDS------------------------------------------------
struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company

int mega_helper(struct Employee* emp, int emp_id, int level){
    if(CEO->emp_id == emp_id){
        push(CEO, NULL,0);
        return 1;
    }
    if(emp->subordinate_1 == NULL && emp->subordinate_2 == NULL)
        return 0;

    else if(emp->subordinate_1 == NULL){
        if(emp->subordinate_2->emp_id == emp_id){
            push(emp->subordinate_2, emp,level+1);
            return 1;
        }
        else{
            return mega_helper(emp->subordinate_2, emp_id,level+1);
        }
    }
    
    else if(emp->subordinate_2 == NULL){
        if(emp->subordinate_1->emp_id == emp_id){
            push(emp->subordinate_1, emp,level+1);
            return 1;
        }
        else{
            return mega_helper(emp->subordinate_1, emp_id,level+1);
        }
    }
    else{
        if(emp->subordinate_1->emp_id == emp_id){
            push(emp->subordinate_1, emp,level+1);
            return 1;
        }
        else if(emp->subordinate_2->emp_id == emp_id){
            push(emp->subordinate_2, emp,level+1);
            return 1;
        }
        else{
            return (mega_helper(emp->subordinate_1, emp_id,level+1) || mega_helper(emp->subordinate_2, emp_id,level+1));
        }
    }
}

int check_if_in(struct Employee* emp, int emp_id){
    if(emp == NULL)
        return 0;
    if(emp->emp_id == emp_id)
        return 1;
    else{
        return (check_if_in(emp->subordinate_1, emp_id) || check_if_in(emp->subordinate_2, emp_id));
    }
}

// The below function returns the employee id of the first common boss
int get_first_common_boss_(int emp_id1, int emp_id2){
    if(CEO == NULL)
        return -1;
    if(CEO->emp_id == emp_id1 && CEO->emp_id == emp_id2)
        return -1;
    if(CEO->emp_id == emp_id1 || CEO->emp_id == emp_id2)
        return CEO->emp_id;
    if(emp_id1 == emp_id2)
        // clear();
        // mega_helper(CEO,emp_id1,0);
        // int boss_emp = PythonListHead->boss->emp_id;
        // clear();
        return emp_id1;
    clear();
    int val1 = mega_helper(CEO, emp_id1,0);
    if(val1){
        if(PythonListHead->boss == NULL)
            return CEO->emp_id;
        else if(check_if_in(PythonListHead->emp, emp_id2)){
            return emp_id1;
        }
        else{
            struct Employee* store = PythonListHead->boss;
            clear();
            int check = check_if_in(store,emp_id2);
            if(check)
                return store->emp_id;
            else
                return get_first_common_boss_(store->emp_id,emp_id2);
        }
    }
    }

    int get_first_common_boss(int emp_id1, int emp_id2){
        if(CEO == NULL)
            return -1;
        if(CEO->emp_id == emp_id1 && CEO->emp_id == emp_id2)
        return -1;
        if(CEO->emp_id == emp_id1 || CEO->emp_id == emp_id2)
            return CEO->emp_id;
        if(emp_id1 == emp_id2){
            clear();
            mega_helper(CEO,emp_id1,0);
            int boss_emp = PythonListHead->boss->emp_id;
            clear();
            return boss_emp;
            }
        else
            return get_first_common_boss_(emp_id1,emp_id2);
    }

//Print the employees with the same last name sperated by a space in the order of their level
//required - level and employee_id
void same_last_name_helper(char* name_pt, struct Employee* emp, int lvl){
    if(!emp)
        return;
    if(strcmp(name_pt,emp->emp_name) == 0){
        append(emp->emp_id, lvl);
    }
    same_last_name_helper(name_pt, emp->subordinate_1,lvl+1);
    same_last_name_helper(name_pt, emp->subordinate_2,lvl+1);
}


void same_last_names(int emp_id){
    clear();
    int val = mega_helper(CEO,emp_id,0);
    if(val){    
        char* name_pt = PythonListHead->emp->emp_name; // name_pt is the pointer to the name, or an array of characters., compare
        clear();
        clear_1();
        same_last_name_helper(name_pt,CEO,0);
        int i = 1;
        int n = print_emp_id_max_lvl(0);
        while(i <= n){
            print_emp_id_max_lvl(i);
            i++;
        }
        clear_1();
    }
    return;
}

// Print the bosses of the given employee in the order from CEO to immediate boss
void get_all_bosses_h(struct Employee* boss){
    if(boss->emp_id == CEO->emp_id){
        append(CEO->emp_id, 0);
        return;
    }
    append(boss->emp_id, 0);
    clear();
    mega_helper(CEO,boss->emp_id,0);
    get_all_bosses_h(PythonListHead->boss);
    return;
}

void get_all_bosses(int emp_id){
    clear();
    mega_helper(CEO, emp_id,0);
    if(PythonListHead->boss == NULL){
        printf("%d ", -1);
        return;
    }
    get_all_bosses_h(PythonListHead->boss);
    struct Node_1* node = PythonListHead_1;
    while(node){
        printf("%d ", node->data);
        node = node->next;
    }
    clear();
    clear_1();
    return;
}

int number_of_nodes(struct Employee* emp){
    if(!emp)
        return 0;
    return (number_of_nodes(emp->subordinate_1) + number_of_nodes(emp->subordinate_2) + 1);
}

double salary(struct Employee* emp){
    if(!emp)
        return 0;
    return (salary(emp->subordinate_1) + salary(emp->subordinate_2) + emp->emp_salary);
}

// Return the average salary of the team with the given employee as head
double get_average_salary(int emp_id){
    clear();
    int val = mega_helper(CEO,emp_id,0);
    if(!val)
        return 0.0;
    double n = number_of_nodes(PythonListHead->emp);
    double sum = salary(PythonListHead->emp);
    double avg;
    avg = sum/n;
    return avg;
}
// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "get_first_common_boss") == 0) {
            int x,y;
            scanf("%d %d", &x, &y);
            int ans = get_first_common_boss(x,y);
            printf("%d\n", ans);
        } 
        else if(strcmp(operation_type, "same_last_names") == 0) {
            int x;
            scanf("%d", &x);
            same_last_names(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_all_bosses") == 0) {
            int x;
            scanf("%d", &x);
            get_all_bosses(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_average_salary") == 0) {
            int x;
            scanf("%d", &x);
            double ans = get_average_salary(x);
            printf("%.2f\n", ans);
        } 

    }

    return 0;
}
