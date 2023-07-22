#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Node {

public:
    string NameData, IDData, AddrData, PhonData;
    double InvoiceData;

    Node* next;
};

bool CheckRecord(Node* headptr,string id)
{
    if (headptr == NULL)
        return false;
    else{
      Node* Temp =headptr;
      while (Temp != NULL) {
         if (Temp->IDData == id)
              return true;
      Temp = Temp->next;
    }
    return false;
  }
}
void CreateRecord(Node** headptr,string NameData, string IDData, string AddrData,
    string PhonData, double InvoiceData)
{
   // bool flag=CheckRecord(headptr,IDData);
    if(CheckRecord(*headptr,IDData)) {
        cout << "The record is already exists\n";
        return;
    }
    Node* newNode = new Node();
    newNode->IDData = IDData;
    newNode->NameData = NameData;
    newNode->AddrData = AddrData;
    newNode->PhonData = PhonData;
    newNode->InvoiceData = InvoiceData;

    newNode->next = NULL;

    if (*headptr == NULL ){//|| (*headnode)->IDData >= Temp->IDData) {
          newNode->next = *headptr;
          *headptr = newNode;
    }
    else {
        Node* Temp=*headptr;
        while (Temp->next != NULL ){//&& Temp->next->IDData < Temp->IDData) {
            Temp = Temp->next;
        }
        newNode->next = Temp->next;
        Temp->next = newNode;
    }
    cout << "The Record is Inserted\n";
}
//to check if the ID exist

void showRecord(Node* headptr){
    Node* Temp=headptr;
     if (Temp == NULL) {
        cout << "No Records exist\n";
    }
    else {
        
        while (Temp != NULL) {
            cout << "patient ID patient: \n";
            cout << Temp->IDData;
            cout << "\npatient Name: \n";
            cout << Temp->NameData;
            cout << "\npatient Address: \n";
            cout << Temp->AddrData;
            cout << "\npatient Phone Number: \n";
            cout << Temp->PhonData;
            cout << "\npatient Invoice: \n";
            cout << Temp->InvoiceData;
            
            Temp = Temp->next;
        }
    }
}
void SearchRecord(Node* headptr, string id){
    
    if (CheckRecord(headptr,id)) {
         Node* Temp=headptr;
         while (Temp!=NULL) {
             if (Temp->IDData == id) {
                cout << "patient  found!\n" ;
                cout << "patient ID:\n";
                cout << Temp->IDData;
                cout << "\nName of the patient:\n"; 
                cout<< Temp->NameData;
                cout << "\nAddress of the patient:\n";
                cout<< Temp->AddrData;
                cout << "\npatient Phone Number:\n"; 
                cout<< Temp->PhonData;
                cout << "\npatient Invoice:\n"; 
                cout<< Temp->InvoiceData;
                return;
            }  
            Temp = Temp->next;
        }
         cout << "The patient you are searching for is not exist\n";
    }else
      cout << "The system has no record\n";

}
void DeleteRecord(Node** headptr, string id)
{
    if(CheckRecord(*headptr,id)){
    Node* Temp=*headptr;
    Node* helpTemp=NULL;
    while(Temp!=NULL && Temp->next->IDData!=id){
        Temp=Temp->next;
    }
    helpTemp=Temp->next;
    Temp->next=Temp->next->next;
    free(helpTemp);
     cout<<"The record deleted\n";
    
    }else
       cout<<"The record you want to delete is not exist\n";
    
}

void UpdateInvoice(Node** headptr, string id){
     Node* Temp=*headptr;
     if(CheckRecord(*headptr,id))
     {
         while (Temp != NULL)
        {
            if (Temp->InvoiceData > 100)
            {
                Temp->InvoiceData = ( Temp->InvoiceData * 0.15 ) + Temp->InvoiceData;
                cout << "Invoice Updated\n";
                return;
            }
            else if (Temp->InvoiceData < 10){
                Temp->InvoiceData = Temp->InvoiceData * 0 ;
                cout << "Invoice Updated\n";
            }

            Temp = Temp->next;
        }
         
     }else
         cout << "There is no patients by this ID to update their invoice\n";
          
}
int main()
{
    Node *head = new Node();
    head = NULL;
    
    string NameData, IDData, AddrData, PhonData;
    double InvoiceData;
    int ch;

    while (true) {
        cout << "\n\t patient Record Management System\n\n\t";
        cout << "\n\t1. Insert patient Record\n\t";
        cout << "2. Delete an patient record\n\t";
        cout << "3. Show patient Records\n\t";
        cout << "4. Search patient\n\t";
        cout << "5. Update Invoice \n\t";
        cout << "6. Exit \n";
        cout << "\nEnter your Choice\n";

        cin >> ch;
        if (ch == 1) {

            cout << "Enter patient ID\n";
            cin >> IDData;
            cout << "Enter Name of patient\n";
            cin >> NameData;
            cout << "Enter Address of patient\n";
            cin >> AddrData;
            cout << "Enter phone number\n";
            cin >> PhonData;
            cout << "Enter Invoice\n";
            cin >> InvoiceData;
            CreateRecord(&head, NameData, IDData, AddrData, PhonData, InvoiceData);
        }
        else if (ch == 2) {
            cout << "Enter patientID to delete the record\n";
            cin >> IDData;
            DeleteRecord(&head, IDData);
        }
        else if (ch == 3) {
            showRecord(head);
        }
        else if (ch == 4) {
            cout << "Enter ID of patient to Search the record\n";
            cin >> IDData;
            SearchRecord(head, IDData);
        }
        else if (ch == 5)

        {
            cout<<"be carefull if your invoice is more than 100 a tax will be added!, the tax is %15\n";
            cout << "if your invoice is less than 10 your invoice will be 0\n";
            cout << "Enter ID of patient to show The update of invoice the record\n";
            cin >> IDData;
            
            UpdateInvoice(&head, IDData);
        }
        else if (ch == 6) {

            exit(0);
        }
        else {
            cout << "Invalid Choice\n";
        }
    }
    return 0;
}