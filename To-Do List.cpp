#include <iostream>
using namespace std;

struct Node{
    int id;
    char desc[100];
    char dead[11];
    Node* next;
};

Node* head=nullptr;
int aid=1;

bool isEarlier(char dt1[],char dt2[]){
    for(int i=0;i<10;++i){
        if(dt1[i]<dt2[i]){
			return true;
		}
        if(dt1[i]>dt2[i]){
			return false;
		}
    }
    return false;
}

void addTask(){
    Node* newTask=new Node();
    newTask->id=aid++;
    cout<<"Enter Task Description: ";
    cin.ignore();
    cin.getline(newTask->desc, 100);
    cout<<"Enter Task Deadline (YYYY-MM-DD): ";
    cin.getline(newTask->dead, 11);
    newTask->next=nullptr;
    if(head==nullptr || isEarlier(newTask->dead, head->dead)){
        newTask->next=head;
        head=newTask;
    }
    else{
        Node* tmp=head;
        while(tmp->next != nullptr && !isEarlier(newTask->dead, tmp->next->dead)){
            tmp=tmp->next;
        }
        newTask->next=tmp->next;
        tmp->next=newTask;
    }
    cout<<endl<<"Task Added."<<endl;
}


void delTask(){
    if(head==nullptr){
        cout<<endl<<"No Tasks to Delete."<<endl;
        return;
    }
    int id;
    cout<<"Enter Task ID to Delete: ";
    cin>>id;
    Node* tmp=head;
    Node* prev=nullptr;
    while(tmp!=nullptr&&tmp->id!=id){
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp==nullptr){
        cout<<endl<<"Task ID "<<id<<" Not Found."<<endl;
        return;
    }
    if(prev==nullptr){
        head=head->next;
    }
	else{
        prev->next=tmp->next;
    }
    delete tmp;
    cout<<endl<<"Task Deleted"<<endl;
}

void dispTasks(){
    if(head==nullptr){
        cout<<endl<<"No Task."<<endl;
        return;
    }
    Node* tmp=head;
    cout<<endl<<"Task:- "<<endl;
    while(tmp!=nullptr){
        cout<<"ID: "<<tmp->id<<", Description: "<<tmp->desc<<", Deadline: "<<tmp->dead<<endl;
        tmp=tmp->next;
    }
}

int main(){
    int ch;
    do{
        cout<<endl<<"To-Do List:- "<<endl;
        cout<<"1.Add Task"<<endl;
        cout<<"2.Delete Task"<<endl;
        cout<<"3.Display Task"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your Choice:- ";
        cin>>ch;
        switch(ch){
            case 1:
				addTask();
				break;
            case 2:
				delTask();
				break;
            case 3:
				dispTasks();
				break;
            case 4:
				cout<<"Exiting Program"<<endl;
				break;
            default:
				cout<<endl<<"Invalid Choice"<<endl;
        }
    }while(ch!=4);
    return 0;
}

