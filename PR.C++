#include <iostream>
#include <string>
using namespace std;

const int max_book = 2000;
const int in_book = 2;

struct book {
    string title;
    string author;
    string status;
    int id;
};

book library[max_book];
int bookcount = 0;



void showmenu(){
    cout<<"the ilbrary system\n";
    cout<<" 1: display all books\n";
    cout<<" 2: add a new book\n";
    cout<<" 3: search for a book\n";
    cout<<" 4: borrow a book\n";
    cout<<" 5: return a book\n ";
    cout<<" 6: exit\n";
    cout<<"choose option (1 :6)\n";
}

void displayBooks(){

    if (bookcount<=0){
        cout<<"\n no books in library\n";
        return;
    }
    cout<<" all books in library:"<<bookcount<<"\n";

    for (int i =0; i<bookcount; i++ ){
        cout<<"book:"<<i+1<<"\n";
        cout<<"id:"<<library[i].id<<"\n";
        cout<<"title:"<<library[i].title<<"\n";
        cout<<"author:"<<library[i].author<<"\n";
        cout<<"status:"<<library[i].status<<"\n";
    }
}

void addbooks(){

    if (bookcount>= max_book){
        cout<<"\n library is full\n";
        return;
    }
    cout<<"\n add new book\n";
    library[bookcount].id=bookcount+1;
    library[bookcount].status="available";

    cout<<"\nenter book title\n";
    cin.ignore();
    getline(cin,library[bookcount].title);

    cout<<"\nenter author name:\n";
    getline(cin,library[bookcount].author);

    bookcount++;

    cout<<"\n adding book done\n";
}

void searchbook(){
    if (bookcount<=0){
        cout<<"\n no books in library\n";
        return;
    }

    string searchtitle;
    bool found = false;

    cout<<"\n search for a book\n";

    cout<<"\nenter book title\n";
    cin.ignore();
    getline(cin,searchtitle);

    for (int i =0; i<bookcount; i++ ){
        if (library[i].title == searchtitle){
            cout<<"book found\n";
            cout<<"id:"<<library[i].id<<"\n";
            cout<<"title:"<<library[i].title<<"\n";
            cout<<"author:"<<library[i].author<<"\n";
            cout<<"status:"<<library[i].status<<"\n";
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"\nbook not found\n";
    }
}

void borrowbook(){
    if (bookcount<=0){
        cout<<"\n no books in library\n";
        return;
    }
    int bookId;
    bool found = false;

    cout<<"\nborrow a book\n";
    cout<<" \n  enter book id\n";
    cin>>bookId;

    for (int i =0; i<bookcount; i++ ){
        if( library[i].id==bookId){
            found=true;
            if(library[i].status=="available"){
                library[i].status="borrowed";
                cout<<"done\n";
            }
            else{
                cout<<" \n book is borrowed\n";
            }
        }
        break;
    }

    if(!found){
        cout<<"\n invalid id\n";
    }
}

void returnbook(){
    if (bookcount<=0){
        cout<<"\n no books in library\n";
        return;
    }
    int bookId;
    bool found = false;

    cout<<" \n  enter book id\n";
    cin>>bookId;

    for (int i =0; i<bookcount; i++ ){
        if( library[i].id==bookId){
            found=true;
            if(library[i].status=="borrowed"){
                library[i].status="availables";
                cout<<"done\n";
            }
            else{
                cout<<" \n book is availables \n";
            }
        }
        break;
    }

    if(!found){
        cout<<"\n invalid id\n";
    }
}


int main(){

    cout<<"welcome\n";
   

    int choice;
    bool running=true;

    while (running=true){
        showmenu();
        cin>>choice;

        if(choice==1){
            displayBooks();

        }
        else if(choice==2){
            addbooks();

        }
        else if(choice==3){
            searchbook();

        }
        else if(choice==4){
            borrowbook();
        }
        else if(choice==5){
            returnbook();

        }
        else if(choice==6){
            cout<<"thank you for using the library\n";
            running=false;
        }
        else{cout<<"invalid choice";}

    }
    return 0;
}
