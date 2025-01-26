#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// We can create header files for ADTs (Abstract Data Types) using these structs, prototypes and global variables.
// As a result, the user can perform their tasks by only interacting with the main method.

// Struct Definitions
typedef struct Student {
    int id;
    char name[50];
    char surname[50];
    int year;
    int ECTS;
    float grade;
} Student;

// Node Definition for BST
typedef struct BSTNode {
    Student data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Node Definition for AVL
typedef struct AVLNode {
    Student data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Prototypes
void mainMenu();
void arrayMenu();
void bstMenu();
void avlMenu();
void createArray();
void searchArray();

BSTNode* createBSTNode(Student student);
BSTNode* insertBST(BSTNode* root, Student student);
BSTNode* deleteBST(BSTNode* root, int id);
BSTNode* findMin(BSTNode* root);
BSTNode* searchBST(BSTNode* root, int id);
int heightBST(BSTNode* root);
void freeBST(BSTNode* root);

AVLNode* createAVLNode(Student student);
AVLNode* insertAVL(AVLNode* root, Student student);
AVLNode* deleteAVL(AVLNode* root, int id);
AVLNode* rotateRight(AVLNode* y);
AVLNode* rotateLeft(AVLNode* x);
int getBalance(AVLNode* root);
int heightAVL(AVLNode* root);
AVLNode* findMinAVL(AVLNode* root);
AVLNode* searchAVL(AVLNode* root, int id);
void freeAVL(AVLNode* root);

// Global Variables
Student* studentArray = NULL;
int arraySize = 0;

BSTNode* bstRoot = NULL;

AVLNode* avlRoot = NULL;

// Helper Function for Time Calculation
double getTimeInMs() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1000000.0;
}

// Main Menu
void mainMenu() {
    int choice;
    do {
        printf("\nMain Menu\n");
        printf("1. Array Data Structure\n");
        printf("2. BST Data Structure\n");
        printf("3. AVL Data Structure\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: arrayMenu(); break;
            case 2: bstMenu(); break;
            case 3: avlMenu(); break;
            case 4: printf("Exiting program. Have a great day!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Array Menu
void arrayMenu() {
    int choice;
    do {
        printf("\nArray Data Structure Menu\n");
        printf("1. Create Array\n");
        printf("2. Search a student\n");
        printf("3. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createArray(); break;
            case 2: searchArray(); break;
            case 3: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

// Array Functions
void createArray() {
    printf("Enter the number of students: ");
    scanf("%d", &arraySize);

    // Dynamic Memory Allocation
    studentArray = (Student*)malloc(arraySize * sizeof(Student));
    if (studentArray == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    double startTime = getTimeInMs();
    for (int i = 0; i < arraySize; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("ID: "); scanf("%d", &studentArray[i].id);
        printf("Name: "); scanf("%s", studentArray[i].name);
        printf("Surname: "); scanf("%s", studentArray[i].surname);
        printf("Year: "); scanf("%d", &studentArray[i].year);
        printf("ECTS: "); scanf("%d", &studentArray[i].ECTS);
        printf("Grade: "); scanf("%f", &studentArray[i].grade);
    }
    double endTime = getTimeInMs();
    printf("Array is created. Process time = %.2f msec.\n", endTime - startTime);
}

void searchArray() {
    if (studentArray == NULL) {
        printf("Array is not created yet!\n");
        return;
    }

    int searchID;
    printf("Enter ID to search: ");
    scanf("%d", &searchID);

    double startTime = getTimeInMs();
    for (int i = 0; i < arraySize; i++) {
        if (studentArray[i].id == searchID) {
            double endTime = getTimeInMs();
            printf("Found in %.2f msec.\n", endTime - startTime);
            printf("Name: %s\n", studentArray[i].name);
            printf("Surname: %s\n", studentArray[i].surname);
            printf("Year: %d\n", studentArray[i].year);
            printf("ECTS: %d\n", studentArray[i].ECTS);
            printf("Grade: %.2f\n", studentArray[i].grade);
            return;
        }
    }
    double endTime = getTimeInMs();
    printf("Student not found. Search time = %.2f msec.\n", endTime - startTime);
}

// BST Menu
void bstMenu() {
    int choice;
    do {
        printf("\nBST Data Structure Menu\n");
        printf("1. Create BST\n");
        printf("2. Insert a student\n");
        printf("3. Delete a student\n");
        printf("4. Search a student\n");
        printf("5. Height\n");
        printf("6. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (bstRoot != NULL) {
                    freeBST(bstRoot);
                    bstRoot = NULL;
                }
                printf("BST created.\n");
                break;
            }
            case 2: {
                Student newStudent;
                printf("Enter details for the student:\n");
                printf("ID: "); scanf("%d", &newStudent.id);
                printf("Name: "); scanf("%s", newStudent.name);
                printf("Surname: "); scanf("%s", newStudent.surname);
                printf("Year: "); scanf("%d", &newStudent.year);
                printf("ECTS: "); scanf("%d", &newStudent.ECTS);
                printf("Grade: "); scanf("%f", &newStudent.grade);
                double startTime = getTimeInMs();
                bstRoot = insertBST(bstRoot, newStudent);
                double endTime = getTimeInMs();
                printf("Student added. Process time = %.2f msec.\n", endTime - startTime);
                break;
            }
            case 3: {
                int deleteID;
                printf("Enter ID to delete: ");
                scanf("%d", &deleteID);
                double startTime = getTimeInMs();
                bstRoot = deleteBST(bstRoot, deleteID);
                double endTime = getTimeInMs();
                printf("Student removed (if found). Process time = %.2f msec.\n", endTime - startTime);
                break;
            }
            case 4: {
                int searchID;
                printf("Enter ID to search: ");
                scanf("%d", &searchID);
                double startTime = getTimeInMs();
                BSTNode* foundNode = searchBST(bstRoot, searchID);
                double endTime = getTimeInMs();
                if (foundNode != NULL) {
                    Student student = foundNode->data;
                    printf("Found in %.2f msec.\n", endTime - startTime);
                    printf("Name: %s\n", student.name);
                    printf("Surname: %s\n", student.surname);
                    printf("Year: %d\n", student.year);
                    printf("ECTS: %d\n", student.ECTS);
                    printf("Grade: %.2f\n", student.grade);
                } else {
                    printf("Student not found. Search time = %.2f msec.\n", endTime - startTime);
                }
                break;
            }
            case 5: {
                double startTime = getTimeInMs();
                int h = heightBST(bstRoot);
                double endTime = getTimeInMs();
                printf("Height of the BST is %d. Process time = %.2f msec.\n", h, endTime - startTime);
                break;
            }
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

// BST Functions
BSTNode* createBSTNode(Student student) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = student;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* insertBST(BSTNode* root, Student student) {
    if (root == NULL) {
        return createBSTNode(student);
    }
    if (student.id < root->data.id) {
        root->left = insertBST(root->left, student);
    } else if (student.id > root->data.id) {
        root->right = insertBST(root->right, student);
    }
    return root;
}

BSTNode* deleteBST(BSTNode* root, int id) {
    if (root == NULL) {
        return NULL;
    }
    if (id < root->data.id) {
        root->left = deleteBST(root->left, id);
    } else if (id > root->data.id) {
        root->right = deleteBST(root->right, id);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        } else {
            BSTNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data.id);
        }
    }
    return root;
}

BSTNode* findMin(BSTNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

BSTNode* searchBST(BSTNode* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }
    if (id < root->data.id) {
        return searchBST(root->left, id);
    }
    return searchBST(root->right, id);
}

int heightBST(BSTNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = heightBST(root->left);
    int rightHeight = heightBST(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void freeBST(BSTNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

// AVL Menu
void avlMenu() {
    int choice;
    do {
        printf("\nAVL Data Structure Menu\n");
        printf("1. Create AVL\n");
        printf("2. Insert a student\n");
        printf("3. Delete a student\n");
        printf("4. Search a student\n");
        printf("5. Height\n");
        printf("6. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (avlRoot != NULL) {
                    freeAVL(avlRoot);
                    avlRoot = NULL;
                }
                printf("AVL created.\n");
                break;
            }
            case 2: {
                Student newStudent;
                printf("Enter details for the student:\n");
                printf("ID: "); scanf("%d", &newStudent.id);
                printf("Name: "); scanf("%s", newStudent.name);
                printf("Surname: "); scanf("%s", newStudent.surname);
                printf("Year: "); scanf("%d", &newStudent.year);
                printf("ECTS: "); scanf("%d", &newStudent.ECTS);
                printf("Grade: "); scanf("%f", &newStudent.grade);
                double startTime = getTimeInMs();
                avlRoot = insertAVL(avlRoot, newStudent);
                double endTime = getTimeInMs();
                printf("Student added. Process time = %.2f msec.\n", endTime - startTime);
                break;
            }
            case 3: {
                int deleteID;
                printf("Enter ID to delete: ");
                scanf("%d", &deleteID);
                double startTime = getTimeInMs();
                avlRoot = deleteAVL(avlRoot, deleteID);
                double endTime = getTimeInMs();
                printf("Student removed (if found). Process time = %.2f msec.\n", endTime - startTime);
                break;
            }
            case 4: {
                int searchID;
                printf("Enter ID to search: ");
                scanf("%d", &searchID);
                double startTime = getTimeInMs();
                AVLNode* foundNode = searchAVL(avlRoot, searchID);
                double endTime = getTimeInMs();
                if (foundNode != NULL) {
                    Student student = foundNode->data;
                    printf("Found in %.2f msec.\n", endTime - startTime);
                    printf("Name: %s\n", student.name);
                    printf("Surname: %s\n", student.surname);
                    printf("Year: %d\n", student.year);
                    printf("ECTS: %d\n", student.ECTS);
                    printf("Grade: %.2f\n", student.grade);
                } else {
                    printf("Student not found. Search time = %.2f msec.\n", endTime - startTime);
                }
                break;
            }
            case 5: {
                double startTime = getTimeInMs();
                int h = heightAVL(avlRoot);
                double endTime = getTimeInMs();
                printf("Height of the AVL is %d. Process time = %.2f msec.\n", h, endTime - startTime);
                break;
            }
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

// AVL Functions
AVLNode* createAVLNode(Student student) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = student;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int heightAVL(AVLNode* root) {
    return root == NULL ? 0 : root->height;
}

int getBalance(AVLNode* root) {
    return root == NULL ? 0 : heightAVL(root->left) - heightAVL(root->right);
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (heightAVL(y->left) > heightAVL(y->right) ? heightAVL(y->left) : heightAVL(y->right));
    x->height = 1 + (heightAVL(x->left) > heightAVL(x->right) ? heightAVL(x->left) : heightAVL(x->right));
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (heightAVL(x->left) > heightAVL(x->right) ? heightAVL(x->left) : heightAVL(x->right));
    y->height = 1 + (heightAVL(y->left) > heightAVL(y->right) ? heightAVL(y->left) : heightAVL(y->right));
    return y;
}

AVLNode* insertAVL(AVLNode* root, Student student) {
    if (root == NULL) {
        return createAVLNode(student);
    }
    if (student.id < root->data.id) {
        root->left = insertAVL(root->left, student);
    } else if (student.id > root->data.id) {
        root->right = insertAVL(root->right, student);
    } else {
        return root; // Duplicate IDs not allowed
    }

    root->height = 1 + (heightAVL(root->left) > heightAVL(root->right) ? heightAVL(root->left) : heightAVL(root->right));
    int balance = getBalance(root);

    // Balance Checks and Rotations
    if (balance > 1 && student.id < root->left->data.id) {
        return rotateRight(root);
    }
    if (balance < -1 && student.id > root->right->data.id) {
        return rotateLeft(root);
    }
    if (balance > 1 && student.id > root->left->data.id) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && student.id < root->right->data.id) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

AVLNode* deleteAVL(AVLNode* root, int id) {
    if (root == NULL) {
        return NULL;
    }
    if (id < root->data.id) {
        root->left = deleteAVL(root->left, id);
    } else if (id > root->data.id) {
        root->right = deleteAVL(root->right, id);
    } else {
        if (root->left == NULL || root->right == NULL) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = findMinAVL(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data.id);
        }
    }
    if (root == NULL) {
        return NULL;
    }
    root->height = 1 + (heightAVL(root->left) > heightAVL(root->right) ? heightAVL(root->left) : heightAVL(root->right));
    int balance = getBalance(root);

    // Balance Checks and Rotations
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

AVLNode* findMinAVL(AVLNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

AVLNode* searchAVL(AVLNode* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }
    if (id < root->data.id) {
        return searchAVL(root->left, id);
    }
    return searchAVL(root->right, id);
}

void freeAVL(AVLNode* root) {
    if (root != NULL) {
        freeAVL(root->left);
        freeAVL(root->right);
        free(root);
    }
}

int main() {
    int choice;
    createArray(); // Creating an array before program starts
    BSTNode* bstRoot = NULL;   // BST Root Initialization
    AVLNode* avlRoot = NULL;   // AVL Root Initialization

    mainMenu();

    // Memory Cleanup Operations
    if (studentArray != NULL) {
        free(studentArray); // Memory Deallocation
    }
    freeBST(bstRoot);
    freeAVL(avlRoot);

    return 0;
}