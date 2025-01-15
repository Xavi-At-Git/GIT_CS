#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

struct Customer {
    int custid;
    char custname[50];
    char custphno[15];
};

struct Customer hashTable[TABLE_SIZE];

int hashFunction(int custid) {
    return custid % TABLE_SIZE;
}

void insertCustomer(int custid, const char *custname, const char *custphno) {
    int index = hashFunction(custid);
    while (hashTable[index].custid != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index].custid = custid;
    strcpy(hashTable[index].custname, custname);
    strcpy(hashTable[index].custphno, custphno);
}

void searchCustomer(int custid) {
    int index = hashFunction(custid);
    int start = index;
    while (hashTable[index].custid != -1) {
        if (hashTable[index].custid == custid) {
            printf("Customer found:\nID: %d, Name: %s, Phone: %s\n",
                   hashTable[index].custid, hashTable[index].custname, hashTable[index].custphno);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }
    printf("Customer not found for ID %d\n", custid);
}

void displayRecords() {
    printf("Customer Records:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].custid != -1) {
            printf("Index %d: (ID: %d, Name: %s, Phone: %s)\n",
                   i, hashTable[i].custid, hashTable[i].custname, hashTable[i].custphno);
        }
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i].custid = -1;

    insertCustomer(101, "Ajay", "9562385665");
    insertCustomer(205, "Pooja", "9874523610");
    insertCustomer(312, "Swayam", "7895463210");

    displayRecords();

    int data;
    printf("\nEnter Customer ID to search: ");
    scanf("%d", &data);
    searchCustomer(data);

    return 0;
}
