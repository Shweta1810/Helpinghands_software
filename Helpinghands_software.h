#ifndef STAFFING_SYSTEM_H
#define STAFFING_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 64

/* ---------- Enums ---------- */
typedef enum
{
    PACKAGING = 1,
    DELIVERY,
    SORTING
} Sector;
typedef enum
{
    DAY = 1,
    NIGHT
} Timing;

/* ---------- Struct Definitions ---------- */
typedef struct Helper
{
    int id;
    int preference_num;
    Sector sector;
    int wages;
    Timing timing;
    int extra_preference_flag;
    struct Helper *next;
} Helper;

typedef struct Neigh
{
    char branch_name[NAME_LEN];
    struct Neigh *next;
} Neigh;

typedef struct Branch
{
    char name[NAME_LEN];
    Helper *helpers_head;
    Neigh *adj;
    struct Branch *left, *right;
} Branch;

typedef struct QNode
{
    int helper_id;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front, *rear;
} Queue;

/* ---------- External Globals ---------- */
extern Branch *root;
extern int nextHelperID;

/* ---------- Function Prototypes ---------- */

/* Queue */
Queue *createQueue();
void enqueueID(Queue *, int);
int dequeueID(Queue *);
int queueEmpty(Queue *);
void freeQueue(Queue *);

/* Input utility */
void read_line(char *, int);

/* BST */
Branch *createBranchNode(const char *);
Branch *insertBranch(Branch *, const char *);
Branch *findBranch(Branch *, const char *);
Branch *removeBranchNode(Branch *, const char *);

/* Linked List for Helpers */
void insertHelperToBranch(Branch *, Helper *);
int removeHelperFromBranch(Branch *, int);
int removeHelperByID_traverse(Branch *, int);
int searchHelperByID(Branch *, int);

/* Graph */
void addEdge(Branch *, const char *);

/* Menu operations */
void optionAddBranch();
void optionRemoveBranch();
void optionRegisterHelpers();
void optionRemoveHelperByID();
void optionViewBranches();
void optionHelpersByBranch();
void optionTotalHelpersDetails();
void optionRemoveHelperDuplicate();
void optionSearchHelperByNumber();
void optionConnectTwoBranches();
void printMenu();

#endif
