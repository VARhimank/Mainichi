#include<bits/stdc++.h>
using namespace std;

class user{
    string userName;
    int userId;
    int token;
    int currentBookId;
    
    public:
    user(){
        token = 0;
    }

    void Uinitial(){
        cout<<"\nName of User : ";cin>>userName;
        cout<<"User Id : ";cin>>userId;
    }
    void Udisplay(){
        cout<<"\nName of User : ";cout<<userName;
        cout<<"\t| User Id : ";cout<<userId;
        if(token==0){cout<<"\n** Can issue books **";}
        else{cout<<"\n** Cannot issue books **";}
    }
    int tokenRet(){return token;}
    void modifyToken(int n){token = token + n;}
    int userIdRet(){return userId;}
    void userCurrentBookId(){cin>>currentBookId;}
    void modifyCurrentBookId(){currentBookId=NULL;}
    int userCurrentBookIdRet(){return currentBookId;}
};

class book{
    string bookTitle;
    int bookId;

    public:
    void Binitial(){
        cout<<"\nName of Book : ";cin>>bookTitle;
        cout<<"Book Id : ";cin>>bookId;
    }
    void Bdisplay(){
        cout<<"\nName of Book : ";cout<<bookTitle;
        cout<<"\t| Book Id : ";cout<<bookId;
    }
    int bookIdRet(){return bookId;}
};

class Library{
    user u[2];
    book b[2];
    string bookIssue;
    int bookReturnId;
    int userIssueId;
    
    public:
    void registerBooks(){
        for(int i=0;i<2;i++){
            b[i].Binitial();
        }
    }

    void registerUsers(){
        for(int i=0;i<2;i++){
            u[i].Uinitial();
        }
    }
    
    void issueWindow(){
        cout<<"\n\n** BOOK ISSUE Window **";
        cout<<"\nEnter User Id : ";cin>>userIssueId;
        for(int i=0;i<2;i++){
            if(userIssueId == u[i].userIdRet()){
                cout<<"User Found!\n"<<"\nYour details :";
                u[i].Udisplay();

                if(u[i].tokenRet()==0){
                    u[i].modifyToken(1);
                    cout<<"\nSelect your book from the list :-";
                    for(int k=0;k<2;k++){
                        b[k].Bdisplay();
                    }
                    cout<<"\nEnter the book id of the book you want to issue : ";u[i].userCurrentBookId();
                    for(int j=0;j<2;j++){
                        if(u[i].userCurrentBookIdRet() == b[j].bookIdRet()){
                            cout<<"Book Found!\n"<<"Your book details :";
                            b[j].Bdisplay();
                            cout<<"\nEnter date of issue(dd/mm/yyyy) : ";cin>>bookIssue;
                            cout<<"\nSuccessfully Issued the book !\n"<<"Date of return will be 7 days from now";
                        }
                    }
                }
            }
        }
    }


    void returnWindow(){
        cout<<"\n\n** BOOK RETURN Window **";
        cout<<"\nEnter User Id : ";cin>>userIssueId;
        for(int i=0;i<2;i++){
            if(userIssueId == u[i].userIdRet()){
                cout<<"\nUser Found!\n"<<"\nYour details :";
                u[i].Udisplay();

                if(u[i].tokenRet()==1){
                    cout<<"\nIssue Details: ";
                    for(int j=0;j<2;j++){
                        if(u[i].userCurrentBookIdRet() == b[j].bookIdRet()){
                            b[j].Bdisplay();

                            cout<<"\nEnter the book id for the book you want to return : ";cin>>bookReturnId;
                            if(bookReturnId == b[j].bookIdRet()){
                                u[i].modifyToken(-1);
                                u[i].modifyCurrentBookId();
                                cout<<"\n** Successfully Returned the book **";
                            }
                        }
                    }
                }else{cout<<"You don't have any books to return";}
            }
        }
    }

    void records(){
        for(int i=0;i<2;i++){
            u[i].Udisplay();
            if(u[i].tokenRet() != 0){
                for(int j=0;j<2;j++){
                    if(u[i].userCurrentBookIdRet() == b[j].bookIdRet()){
                        b[j].Bdisplay();
                    }
                }
                cout<<"\nDate of issue(dd/mm/yyyy) : "<<bookIssue<<endl;
            }
        }
    }
};

int main(){
    system("cls");

    Library l;
    int choice;

    l.registerBooks();
    l.registerUsers();
    
   do{
        cout<<"\n\n** MAIN MENU **";
        cout<<"\n1. BOOK ISSUE";
        cout<<"\n2. BOOK DEPOSIT";
        cout<<"\n3. RECORDS";
        cout<<"\n4. EXIT";
        cout<<"\nPlease Select Your Choice(1-3) : ";cin>>choice;
        switch(choice){
            case 1: l.issueWindow();
                    break;
            case 2: l.returnWindow();
                    break;
            case 3: l.records();
                    break;
            case 4: exit(1);
                    break;
            }
    }while(choice!=4);

    return 0;
}
